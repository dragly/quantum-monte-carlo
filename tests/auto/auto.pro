TEMPLATE = app

CONFIG   += console
CONFIG   -= app_bundle
CONFIG   -= qt

LIBS += -lunittest++

SOURCES += main.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

include(../../defaults.pri)

SOURCES += $$system(find $$SRC_DIR -name '*.cpp')
SOURCES = $$replace(SOURCES, $$SRC_DIR/main.cpp, )
