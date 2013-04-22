#ifndef HYDROGENWAVEFUNCTION_H
#define HYDROGENWAVEFUNCTION_H

#include <src/wavefunction/wavefunction.h>
#include <src/wavefunction/slater.h>

class HydrogenWaveFunction : public WaveFunction
{
public:
    HydrogenWaveFunction(int nParticles, int nDimensions, int nVariationalParameters);

//    void updateNextEvaluation();
    double evaluate(const mat &positions);

    ~HydrogenWaveFunction();
protected:
    Slater m_upSlater;
    Slater m_downSlater;
    vector<Orbital*> m_orbitals;
};

#endif // HYDROGENWAVEFUNCTION_H
