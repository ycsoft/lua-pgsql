#-------------------------------------------------
#
# Project created by QtCreator 2015-09-01T12:31:54
#
#-------------------------------------------------

QT       -= core gui

TARGET = libpgsql
TEMPLATE = lib

DEFINES += LIBPGSQL_LIBRARY

SOURCES += libpgsql.cpp

HEADERS += libpgsql.h\
        libpgsql_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

INCLUDEPATH += "D:\Program Files (x86)\LuaJIT-2.0.3\include"
INCLUDEPATH += "D:\Program Files (x86)\PostgreSQL\9.3\include"

LIBS += "D:\Program Files (x86)\PostgreSQL\9.3\lib\libpq.lib"
LIBS += "D:\Program Files (x86)\LuaJIT-2.0.3\lib\lua51.lib"
