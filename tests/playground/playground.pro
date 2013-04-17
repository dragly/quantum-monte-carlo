#-------------------------------------------------
#
# Project created by QtCreator 2013-04-17T11:45:50
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_playgroundtest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_playgroundtest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

include(../../defaults.pri)

SOURCES += $$SRC_DIR/wavefunction/wavefunction.cpp
