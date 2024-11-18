module;

#include "lua/lua.hpp"

export module luamanager;

void TEST() {
    char buff[256];
    int error;
    lua_State* L = 0;
	luaL_openlibs(L);
}