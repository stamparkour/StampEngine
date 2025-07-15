module;

#include <cstdarg>
#include "jolt.h"
#include "debug.h"

export module physics;

import std;
import math;

using namespace JPH;
// If you want your code to compile using single or double precision write 0.0_r to get a Real value that compiles to double or float depending if JPH_DOUBLE_PRECISION is set or not.
using namespace JPH::literals;

namespace physics {
	class PhysicsManager;
};

void TraceImpl(const char* inFMT, ...) {
	// Format the message
	va_list list;
	va_start(list, inFMT);
	char buffer[1024];
	vsnprintf(buffer, sizeof(buffer), inFMT, list);
	va_end(list);

	// Print to the TTY
	std::cout << buffer << std::endl;
}

#ifdef JPH_ENABLE_ASSERTS

// Callback for asserts, connect this to your own assert handler if you have one
bool AssertFailedImpl(const char* inExpression, const char* inMessage, const char* inFile, uint inLine) {
	// Print to the TTY
	std::cout << inFile << ":" << inLine << ": (" << inExpression << ") " << (inMessage != nullptr ? inMessage : "") << std::endl;

	// Breakpoint
	return true;
}
#endif // JPH_ENABLE_ASSERTS

namespace physics {
	export enum struct PhysicsLayer {
		NonMoving,
		Moving,
		//FineDetail,
		MAX
	};

	class JoltControl : 
		public ObjectLayerPairFilter,
		public BroadPhaseLayerInterface,
		public ObjectVsBroadPhaseLayerFilter
	{
	public:
		virtual bool ShouldCollide(ObjectLayer inObject1, ObjectLayer inObject2) const override
		{
			PhysicsLayer o1 = (PhysicsLayer)inObject1;
			PhysicsLayer o2 = (PhysicsLayer)inObject2;
			switch (o1)
			{
			case PhysicsLayer::NonMoving:
				return o2 == PhysicsLayer::Moving; // Non moving only collides with moving
			case PhysicsLayer::Moving:
				return true; // Moving collides with everything
			default:
				JPH_ASSERT(false);
				return false;
			}
		}

		virtual bool ShouldCollide(ObjectLayer inLayer1, BroadPhaseLayer inLayer2) const override {
			PhysicsLayer o1 = (PhysicsLayer)inLayer1;
			PhysicsLayer o2 = (PhysicsLayer)inLayer2.GetValue();
		
			switch (o1)
			{
			case PhysicsLayer::NonMoving:
				return o2 == PhysicsLayer::Moving;
			case PhysicsLayer::Moving:
				return true;
			default:
				JPH_ASSERT(false);
				return false;
			}
		}

		virtual uint GetNumBroadPhaseLayers() const override {
			return (uint)PhysicsLayer::MAX;
		}

		virtual BroadPhaseLayer	GetBroadPhaseLayer(ObjectLayer inLayer) const override {
			return (BroadPhaseLayer)inLayer;
		}
	};

	class ObjectListener : public ContactListener, public BodyActivationListener {
	public:
		class PhysicsManager* manager;
		// See: ContactListener
		virtual ValidateResult OnContactValidate(const Body& inBody1, const Body& inBody2, RVec3Arg inBaseOffset, const CollideShapeResult& inCollisionResult) override {
			// Allows you to ignore a contact before it is created (using layers to not make objects collide is cheaper!)
			return ValidateResult::AcceptAllContactsForThisBodyPair;
		}

		virtual void OnContactAdded(const Body& inBody1, const Body& inBody2, const ContactManifold& inManifold, ContactSettings& ioSettings) override;

		virtual void OnContactPersisted(const Body& inBody1, const Body& inBody2, const ContactManifold& inManifold, ContactSettings& ioSettings) override;

		virtual void OnContactRemoved(const SubShapeIDPair& inSubShapePair) override;

		virtual void OnBodyActivated(const BodyID& inBodyID, uint64 inBodyUserData) override;

		virtual void OnBodyDeactivated(const BodyID& inBodyID, uint64 inBodyUserData) override;
	};

	export class PhysicsManager  final {
		friend class PhysicsObject;
		friend class ObjectListener;
		JoltControl control{};
		ObjectListener listener{};

		//setup of Jolt memory and threads
		TempAllocatorImpl* temp_allocator;
		JobSystemThreadPool* job_system;
		float deltaTime = 0;

		PhysicsManager() {
			listener.manager = this;
			// Initialize Jolt
			RegisterDefaultAllocator();
			Trace = TraceImpl;
			JPH_IF_ENABLE_ASSERTS(AssertFailed = AssertFailedImpl;)

				//deserialization of Jolt
				Factory::sInstance = new Factory();

			// Register all physics types with the factory
			RegisterTypes();
			temp_allocator = new TempAllocatorImpl{ 10 * 1024 * 1024 };
			job_system = new JobSystemThreadPool{ cMaxPhysicsJobs, cMaxPhysicsBarriers, 4 };

			const uint cMaxBodies = 65536; //max rigid bodies in simulation
			const uint cNumBodyMutexes = 0; // number of mutexes per body (0 for default)
			const uint cMaxBodyPairs = 65536; // max number of broad phase pairs
			const uint cMaxContactConstraints = 10240; // max body pairs - if filled, then object phase through
			physicsSystem.Init(cMaxBodies, cNumBodyMutexes, cMaxBodyPairs, cMaxContactConstraints, control, control, control);

			physicsSystem.SetBodyActivationListener(&listener);
			physicsSystem.SetContactListener(&listener);
		}
	public:
		PhysicsSystem physicsSystem{};
		static inline PhysicsManager* instance = nullptr; //pointer to self for PhysicsObject to access

		float CurrentDeltaTime() {
			return deltaTime;
		}

		static void Initialize() {
			instance = new PhysicsManager();
		}

		void Itterate(float deltaTime) {
			this->deltaTime = deltaTime;
			if (deltaTime > 0.15f) deltaTime = 0.15f;
			const int cCollisionSteps = max(1,(int)ceil(deltaTime * 70));
			physicsSystem.Update(deltaTime, cCollisionSteps, temp_allocator, job_system);
		}

		~PhysicsManager() {
			UnregisterTypes();
			delete Factory::sInstance;
			Factory::sInstance = nullptr;
		}
	};

	export class PhysicsObject {
		friend class ObjectListener;
		bool isSimulated = true;
		bool isAlive = false;
	protected:
		Body* body;
		PhysicsObject() {
			STAMPERROR(!PhysicsManager::instance, "PhysicsObject: PhysicsManager instance is not initialized");
		}

		void Initialize(Shape* shape, float mass, RVec3Arg inPosition, QuatArg inRotation, EMotionType inMotionType, ObjectLayer inObjectLayer) {
			if (isAlive) return;
			isAlive = true;
			shape->SetUserData((uint64)this);
			BodyCreationSettings bodySettings{ shape, inPosition, inRotation, inMotionType, inObjectLayer };
			if (mass > 0) {
				bodySettings.mMassPropertiesOverride.mMass = mass;
				bodySettings.mOverrideMassProperties = EOverrideMassProperties::CalculateInertia;
			}
			bodySettings.mApplyGyroscopicForce = true;
			bodySettings.mUserData = (uint64)this;
			bodySettings.mAllowDynamicOrKinematic = true; // allow dynamic or kinematic bodies to be created
			body = PhysicsManager::instance->physicsSystem.GetBodyInterface().CreateBody(bodySettings);
			PhysicsManager::instance->physicsSystem.GetBodyInterface().AddBody(body->GetID(), EActivation::Activate);
		}

		virtual void OnContactAdded(const Body& inBody1, const Body& inBody2, PhysicsObject& obj2, const ContactManifold& inManifold, ContactSettings& ioSettings) {}

		virtual void OnContactPersisted(const Body& inBody1, const Body& inBody2, PhysicsObject& obj2, const ContactManifold& inManifold, ContactSettings& ioSettings) {}

		//virtual void OnContactRemoved(PhysicsObject& inBody2) {}

		virtual void OnBodyActivated() {}

		virtual void OnBodyDeactivated() {}
	public:

		void DisableBody() {
			if (!isSimulated) return; //already disabled
			isSimulated = false;
			PhysicsManager::instance->physicsSystem.GetBodyInterface().RemoveBody(body->GetID());
		}
		void EnableBody() {
			if (isSimulated) return; //already disabled
			isSimulated = false;
			PhysicsManager::instance->physicsSystem.GetBodyInterface().AddBody(body->GetID(), EActivation::Activate);
		}

		void Destroy() {
			if (!isAlive) return;
			isAlive = false;
			DisableBody();
			PhysicsManager::instance->physicsSystem.GetBodyInterface().DestroyBody(body->GetID());
		}

		virtual ~PhysicsObject() {
			Destroy();
		}
	};
};

void physics::ObjectListener::OnContactAdded(const Body& inBody1, const Body& inBody2, const ContactManifold& inManifold, ContactSettings& ioSettings) {
	PhysicsObject* body1 = (PhysicsObject*)inBody1.GetUserData();
	PhysicsObject* body2 = (PhysicsObject*)inBody2.GetUserData();
	STAMPERROR(!body1 || !body2, "ObjectListener::OnContactAdded: Body user data is not a PhysicsObject");
	body1->OnContactAdded(inBody1, inBody2, *body2, inManifold, ioSettings);
	body2->OnContactAdded(inBody2, inBody1, *body1, inManifold, ioSettings);
}

void physics::ObjectListener::OnContactPersisted(const Body& inBody1, const Body& inBody2, const ContactManifold& inManifold, ContactSettings& ioSettings) {
	PhysicsObject* body1 = (PhysicsObject*)inBody1.GetUserData();
	PhysicsObject* body2 = (PhysicsObject*)inBody2.GetUserData();

	STAMPERROR(!body1 || !body2, "ObjectListener::OnContactAdded: Body user data is not a PhysicsObject");

	body1->OnContactPersisted(inBody1, inBody2, *body2, inManifold, ioSettings);
	body2->OnContactPersisted(inBody2, inBody1, *body1, inManifold, ioSettings);
}
void physics::ObjectListener::OnContactRemoved(const SubShapeIDPair& inSubShapePair) {
	/*PhysicsObject* body1 = (PhysicsObject*)manager->body_interface->GetUserData(inSubShapePair.GetBody1ID());
	PhysicsObject* body2 = (PhysicsObject*)manager->body_interface->GetUserData(inSubShapePair.GetBody2ID());

	STAMPERROR(!body1 || !body2, "ObjectListener::OnContactAdded: Body user data is not a PhysicsObject");

	body1->OnContactRemoved(*body2);
	body2->OnContactRemoved(*body1);*/
}

void physics::ObjectListener::OnBodyActivated(const BodyID& inBodyID, uint64 inBodyUserData) {
	PhysicsObject* body = (PhysicsObject*)inBodyUserData;
	body->OnBodyActivated();
}
void physics::ObjectListener::OnBodyDeactivated(const BodyID& inBodyID, uint64 inBodyUserData) {
	PhysicsObject* body = (PhysicsObject*)inBodyUserData;
	body->OnBodyDeactivated();
}