TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

include(../defaults.pri)

SOURCES += main.cpp \
    wavefunction/wavefunction.cpp \
    wavefunction/hydrogen/hydrogenwavefunction.cpp \
    wavefunction/slater.cpp \
    wavefunction/orbital.cpp \
    wavefunction/hydrogen/hydrogenorbital.cpp

HEADERS += \
    wavefunction/wavefunction.h \
    wavefunction/hydrogen/hydrogenwavefunction.h \
    wavefunction/slater.h \
    wavefunction/orbital.h \
    wavefunction/hydrogen/hydrogenorbital.h

