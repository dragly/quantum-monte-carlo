#ifndef HYDROGENORBITAL_H
#define HYDROGENORBITAL_H

#include <src/wavefunction/orbital.h>

class HydrogenOrbital : public Orbital
{
public:
    HydrogenOrbital();

    double evaluate(const vec &position, int particleNumber);
};

#endif // HYDROGENORBITAL_H
