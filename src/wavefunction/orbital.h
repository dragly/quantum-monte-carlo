#ifndef ORBITAL_H
#define ORBITAL_H

#include <armadillo>

using namespace arma;

class Orbital
{
public:
    Orbital();
    virtual double evaluate(const vec& position, int particleNumber) = 0;
};

#endif // ORBITAL_H
