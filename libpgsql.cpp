﻿#include "libpgsql.h"

#include <iostream>
#include <libpq-fe.h>

#define     CONN_METATABLE      "pgsql connection metatable"

using namespace std;

int sayHello(lua_State *L)
{
    cout<<"Hello C++ in Lua"<<endl;
    return 0;
}

static PGconn *
pgsql_conn(lua_State *L, int n)
{
    PGconn **data;

    data = (PGconn**)luaL_checkudata(L, n, CONN_METATABLE);
    luaL_argcheck(L, *data != NULL, n, "database connection is finished");
    return *data;
}

int luaopen_pgsql(lua_State *L)
{
    struct luaL_Reg luapgsql[] = {
    {"sayHello",sayHello},
    {"connectdb",connectdb},
    {NULL,NULL}
    };
    struct luaL_Reg  connMethod[] = {
    {"exec",execQuery},
    {NULL,NULL}
    };
    luaL_register(L,"pgsql",luapgsql);
    if (luaL_newmetatable(L,CONN_METATABLE))
    {

        luaL_register(L,NULL,connMethod);
        lua_pushliteral(L,"__index");
        lua_pushvalue(L,-2);
        lua_settable(L,-3);
    }


    return 0;
}

int connectdb(lua_State *L)
{
    PGconn **data;

    data = (PGconn**)lua_newuserdata(L,sizeof(*data));
    const char *conninfo = luaL_checkstring(L,1);
    if ( strcmp(conninfo,"") == 0 )
    {
        lua_pushstring(L,"error because connnection string is empty");
        lua_error(L);
    }
    *data = PQconnectdb(conninfo);

    if (*data != NULL)
    {
        luaL_getmetatable(L,CONN_METATABLE);
        lua_setmetatable(L,-2);
        cout<<"Connect OK"<<endl;
    }else
    {
        lua_pushnil(L);
    }

    return 1;
}

int execQuery(lua_State *L)
{
    PGconn *conn = pgsql_conn(L,1);
    const char *sql = luaL_checkstring(L,2);
    cout<<"SQL:"<<sql<<endl;
    PGresult *result = PQexec(conn,sql);
    char *value = PQgetvalue(result,0,0);
    cout<<value<<endl;
    lua_pushstring(L,value);
    return 1;
}