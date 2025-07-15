//export module Economy;
//
//import std;
//
//export namespace economic {
//
//	struct ResourceType{
//		enum {
//			Wheat,
//			Grain,
//			Bread,
//			Sugar,
//			SweetBread,
//			Wood,
//			Charcoal,
//			Planks,
//			Coal,
//			GoldOre,
//			Gemstone,
//			CutGemstone,
//			Jewelry,
//			CopperOre,
//			TinOre,
//			BronzeTools,
//			IronOre,
//			IronScrap,
//			Nails,
//			CastIronTools,
//			StoneChunk,
//			CutStone,
//			Gravel,
//			Sand,
//			Clay,
//			Brick,
//			Eggs,
//			Cotton,
//			Sails,
//			Cloth,
//			Clothes,
//			BronzeCoin,
//			SilverCoin,
//			GoldCoin,
//			Max
//		};
//		int _value;
//	};
//
//	struct ResourceBoolean {
//	public:
//		bool resources[ResourceType::Max];
//
//		bool AndAll() {
//			for (auto v = resources; v < std::end(resources); v++)
//				if (!*v) return false;
//			return true;
//		}
//		bool OrAll() {
//			for (auto v = resources; v < std::end(resources); v++)
//				if (*v) return true;
//			return false;
//		}
//		ResourceBoolean operator && (ResourceBoolean& o) const {
//			ResourceBoolean rbo{};
//			for (auto [v, vo, rb] = std::tuple{ resources, o.resources, rbo.resources }; v < std::end(resources); v++, vo++, rb++)
//				*rb = *v && *vo;
//			return rbo;
//		}
//		ResourceBoolean operator || (ResourceBoolean& o) const {
//			ResourceBoolean rbo{};
//			for (auto [v, vo, rb] = std::tuple{ resources, o.resources, rbo.resources }; v < std::end(resources); v++, vo++, rb++)
//				*rb = *v || *vo;
//			return rbo;
//		}
//		ResourceBoolean operator !() const {
//			ResourceBoolean o{};
//			for (auto [v, vo] = std::tuple{ resources, o.resources }; v < std::end(resources); v++, vo++)
//				*vo = !*v;
//			return o;
//		}
//	};
//	struct Resource {
//	public:
//		static const Resource weight;//size, mass, volume, etc.
//		float resources[ResourceType::Max]{};
//
//		Resource() {}
//		Resource(float o) {
//			for (auto v = resources; v < std::end(resources); v++)
//				*v = o;
//		}
//		Resource(const float (&arr)[ResourceType::Max]) {
//			std::copy(std::begin(arr), std::end(arr), resources);
//		}
//		Resource& operator = (const Resource& o) {
//			std::copy(std::begin(o.resources), std::end(o.resources), resources);
//			return *this;
//		}
//		Resource& operator += (const Resource& o) {
//			for (auto [v, vo] = std::tuple{ resources, o.resources }; v < std::end(resources); v++, vo++)
//				*v += *vo;
//			return *this;
//		}
//		Resource& operator -= (const Resource& o) {
//			for (auto [v, vo] = std::tuple{ resources, o.resources }; v < std::end(resources); v++, vo++)
//				*v -= *vo;
//			return *this;
//		}
//		Resource& operator *= (const Resource& o) {
//			for (auto [v, vo] = std::tuple{ resources, o.resources }; v < std::end(resources); v++, vo++)
//				*v *= *vo;
//			return *this;
//		}
//		Resource& operator /= (const Resource& o) {
//			for (auto [v, vo] = std::tuple{ resources, o.resources }; v < std::end(resources); v++, vo++)
//				*v /= *vo;
//			return *this;
//		}
//		Resource& operator *= (float o) {
//			for (auto v = resources; v < std::end(resources); v++)
//				*v *= o;
//			return *this;
//		}
//		Resource& operator /= (float o) {
//			for (auto v = resources; v < std::end(resources); v++)
//				*v /= o;
//			return *this;
//		}
//		Resource operator + (const Resource& o) const {
//			Resource v = *this;
//			v += o;
//			return v;
//		}
//		Resource operator - (const Resource& o) const {
//			Resource v = *this;
//			v -= o;
//			return v;
//		}
//		Resource operator - () const {
//			Resource o{};
//			for (auto [v, vo] = std::tuple{ resources, o.resources }; v < std::end(resources); v++, vo++)
//				*vo = -*v;
//			return o;
//		}
//		Resource operator * (const Resource& o) const {
//			Resource v = *this;
//			v *= o;
//			return v;
//		}
//		Resource operator / (const Resource& o) const {
//			Resource v = *this;
//			v /= o;
//			return v;
//		}
//		Resource operator * (float o) const {
//			Resource v = *this;
//			v *= o;
//			return v;
//		}
//		Resource operator / (float o) const {
//			Resource v = *this;
//			v /= o;
//			return v;
//		}
//		ResourceBoolean operator < (const Resource& o) const {
//			ResourceBoolean vbo = {};
//			for (auto [v, vo, vb] = std::tuple{ resources, o.resources, vbo.resources }; v < std::end(resources); v++, vo++, vb++)
//				*vb = *v < *vo;
//			return vbo;
//		}
//		ResourceBoolean operator > (const Resource& o) const {
//			ResourceBoolean vbo = {};
//			for (auto [v, vo, vb] = std::tuple{ resources, o.resources, vbo.resources }; v < std::end(resources); v++, vo++, vb++)
//				*vb = *v > *vo;
//			return vbo;
//		}
//		ResourceBoolean operator <= (const Resource& o) const {
//			ResourceBoolean vbo = {};
//			for (auto [v, vo, vb] = std::tuple{ resources, o.resources, vbo.resources }; v < std::end(resources); v++, vo++, vb++)
//				*vb = *v <= *vo;
//			return vbo;
//		}
//		ResourceBoolean operator >= (const Resource& o) const {
//			ResourceBoolean vbo = {};
//			for (auto [v, vo, vb] = std::tuple{ resources, o.resources, vbo.resources }; v < std::end(resources); v++, vo++, vb++)
//				*vb = *v >= *vo;
//			return vbo;
//		}
//		ResourceBoolean operator < (float o) const {
//			ResourceBoolean vbo = {};
//			for (auto [v, vb] = std::tuple{ resources, vbo.resources }; v < std::end(resources); v++, vb++)
//				*vb = *v < o;
//			return vbo;
//		}
//		ResourceBoolean operator > (float o) const {
//			ResourceBoolean vbo = {};
//			for (auto [v, vb] = std::tuple{ resources, vbo.resources }; v < std::end(resources); v++, vb++)
//				*vb = *v > o;
//			return vbo;
//		}
//		ResourceBoolean operator <= (float o) const {
//			ResourceBoolean vbo = {};
//			for (auto [v, vb] = std::tuple{ resources, vbo.resources }; v < std::end(resources); v++, vb++)
//				*vb = *v <= o;
//			return vbo;
//		}
//		ResourceBoolean operator >= (float o) const {
//			ResourceBoolean vbo = {};
//			for (auto [v, vb] = std::tuple{ resources, vbo.resources }; v < std::end(resources); v++, vb++)
//				*vb = *v >= o;
//			return vbo;
//		}
//
//		friend Resource max(const Resource& a, const Resource& b) {
//			Resource vbo = {};
//			for (auto [v, vo, vb] = std::tuple{ a.resources, b.resources, vbo.resources }; v < std::end(a.resources); v++, vo++, vb++)
//				*vb = std::max(*v, *vo);
//			return vbo;
//		}
//		friend Resource min(const Resource& a, const Resource& b) {
//			Resource vbo = {};
//			for (auto [v, vo, vb] = std::tuple{ a.resources, b.resources, vbo.resources }; v < std::end(a.resources); v++, vo++, vb++)
//				*vb = std::min(*v, *vo);
//			return vbo;
//		}
//	};
//
//	class Buildings {
//		//virtual class for building
//		//calculate consumption and production for building
//	};
//	class People {
//		//calculate consumption of people and waste from people
//		//
//	};
//
//	class EconNode {
//		float maxWeight;
//		float currentWeight;
//		
//		Resource prevStorage[3];
//		Resource storage;
//		Resource minStock;
//		Resource value;
//
//	public:
//		//returns min consume percent
//		float Consume(const Resource& quantity, Resource* excess = 0, bool proportional = false) {
//			if (proportional) {
//				float minPercent = 1;
//				for (int i = 0; i < ResourceType::Max; i++) {
//					float& supply = storage.resources[i];
//					float consumption = quantity.resources[i];
//					if (supply < consumption) {
//						float percent = supply / consumption;
//						if (percent < minPercent)  minPercent = percent;
//					}
//				}
//				for (int i = 0; i < ResourceType::Max; i++) {
//					float& supply = storage.resources[i];
//					float consumption = quantity.resources[i];
//					float c = consumption * minPercent;
//					supply -= c;
//					currentWeight -= Resource::weight.resources[i] * c;
//					if (excess) {
//						excess->resources[i] = consumption - c;
//					}
//				}
//				return minPercent;
//			}
//			else {
//				float minPercent = 1;
//				for (int i = 0; i < ResourceType::Max; i++) {
//					float& supply = storage.resources[i];
//					float consumption = quantity.resources[i];
//					if (supply < consumption) {
//						float percent = supply / consumption;
//						if (percent < minPercent)  minPercent = percent;
//						if (excess) {
//							excess->resources[i] = consumption - supply;
//						}
//						supply = 0;
//					}
//					else {
//						if (excess) {
//							excess->resources[i] = 0;
//						}
//						supply -= consumption;
//					}
//					currentWeight -= Resource::weight.resources[i] * consumption;
//				}
//				return minPercent;
//			}
//		}
//		//returns leftover percent
//		//stockpiles high value over low value
//		float Stockpile(const Resource& quantity, Resource* excess = 0, bool proportional = false) {
//
//		}
//		//everything is not proportional
//		//consume negative
//		//stockpiles positive
//		void Modify(const Resource& resources) {
//
//		}
//
//		void Tick() {
//
//		}
//	};
//
//
//	class EconTransfer {
//	public:
//		Resource resources;
//		//calculates most valuable trade possible
//		EconTransfer(EconNode& A, EconNode& B, float maxWeightTransfer, float valueBias) {
//			//calc difference in value
//			//weight each resource by weight (calculating density value)
//			//find most profitable resource transfers and keep adding them until maxWeight is reached
//			//make sure both have positive economic value modified by valueBias 
//			//valueBias adds a relationship modifier that allows for net loss on value equal to the valueBias
//		}
//
//		void ApplyTransfer() {
//			//call modify of econ nodes
//		}
//	};
//}
//float econWeight[economic::ResourceType::Max]{
//	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
//};
//const  economic::Resource economic::Resource::weight{ 1 };