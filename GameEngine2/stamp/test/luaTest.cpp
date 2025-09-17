#include <stamp/define.h>
#ifdef STAMP_MICROSOFT_UNITTEST

#include <stamp/lua/lua.h>
#include <CppUnitTest.h>

using namespace STAMP_MATH_NAMESPACE;
using namespace STAMP_LUA_NAMESPACE;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace STAMP_MATH_NAMESPACE;

static const char luatest_math[] = R"#(
local Vec2 = require("stamp.Vector2")

local v1 = Vec2:new(1, 2)

return v1
)#";

namespace Lua {

TEST_CLASS(LuaTest) {
public:
	TEST_METHOD(Math) {
		/*lua_State* L = InitializeLua();

		luaL_loadstring(L, luatest_math);
		const char* msg = stamp::lua::luaS_geterror(L, lua_pcallk(L, 0, 1, 0, 0, 0));
		if (msg) Logger::WriteMessage(msg);
		Assert::IsTrue(luaS_isvector2(L, -1));
		lua_Vector2 v1 = luaS_tovector2(L, -1);
		Assert::AreEqual(1.0, v1.x);
		Assert::AreEqual(2.0, v1.y);*/

	}

};
} // namespace Math

#endif