#ifndef LIBPGSQL_H
#define LIBPGSQL_H

#include "libpgsql_global.h"
#include <lua.hpp>

extern "C"
{
    API int sayHello(lua_State *L);
    API int luaopen_pgsql(lua_State *L);
    API int connectdb(lua_State *L);
    API int execQuery(lua_State *L);
    API int close(lua_State *L);

}

#endif // LIBPGSQL_H
