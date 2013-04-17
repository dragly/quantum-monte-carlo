#-------------------------------------------------
#
# Project created by QtCreator 2013-04-17T17:09:14
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_wavefunctiontest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_wavefunctiontest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

include(../../../../defaults.pri)

SOURCES += $$SRC_DIR/wavefunction/wavefunction.cpp
