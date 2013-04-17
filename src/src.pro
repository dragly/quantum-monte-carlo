TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -larmadillo -llapack -lblas

SOURCES += main.cpp \
    wavefunction/wavefunction.cpp

HEADERS += \
    wavefunction/wavefunction.h

