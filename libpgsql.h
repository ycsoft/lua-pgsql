#ifndef LIBPGSQL_H
#define LIBPGSQL_H

#include "libpgsql_global.h"
#include <lua.hpp>

extern "C"
{
    struct  data
    {
        char  name[32];
        int   age;
        int   height;
        int   weight;
    };
    API int sayHello(lua_State *L);
    API int luaopen_pgsql(lua_State *L);
    API int connectdb(lua_State *L);
    API int execQuery(lua_State *L);
    API int close(lua_State *L);
    API int clearResult(lua_State *L);

    //在数据库中保存data类型的数据
    //create table baseinfo( uname varchar(32), age integer, height integer, weight integer);
    API int saveData(lua_State *L);
}

#endif // LIBPGSQL_H
