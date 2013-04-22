#include "hydrogenwavefunction.h"
#include <src/wavefunction/hydrogen/hydrogenorbital.h>

HydrogenWaveFunction::HydrogenWaveFunction(int nParticles, int nDimensions, int nVariationalParameters) :
    WaveFunction(nParticles, nDimensions, nVariationalParameters),
    m_upSlater(nParticles, true),
    m_downSlater(nParticles, false)
{
    // Create orbitals
    m_orbitals.reserve(nParticles / 2);
    for(int i = 0; i < nParticles / 2; i++) {
        HydrogenOrbital* orbital = new HydrogenOrbital();
        m_orbitals.push_back(orbital);
    }

    m_upSlater.setOrbitals(m_orbitals);
    m_downSlater.setOrbitals(m_orbitals);
}

HydrogenWaveFunction::~HydrogenWaveFunction() {
    int nOrbitals = m_orbitals.size();
    for(int i = 0; i < nOrbitals; i++) {
        HydrogenOrbital* orbital = m_orbitals.at(i);
        delete orbital;
    }
}

double HydrogenWaveFunction::evaluate(const mat &positions)
{
    return m_upSlater.evaluateDeterminant(positions) * m_downSlater.evaluateDeterminant(positions);
}
