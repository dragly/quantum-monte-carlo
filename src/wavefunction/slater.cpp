#include "slater.h"

#include <src/wavefunction/orbital.h>

Slater::Slater(int nParticles, bool isSpinUp) :
    m_nParticles(nParticles),
    m_nParticlesHalf(nParticles/2),
    m_isSpinUp(isSpinUp),
    indexOffset(isSpinUp * m_nParticlesHalf)
{
    cout << indexOffset << endl;
}

double Slater::evaluateDeterminant(const mat &positions)
{
    mat tmpMatrix = evaluateMatrix(positions);
    return det(tmpMatrix);
}

const mat Slater::evaluateMatrix(const mat &positions)
{
    mat tmpMatrix = zeros(m_nParticlesHalf, m_nParticlesHalf);
    for(int i = 0; i < m_nParticlesHalf; i++) {
        Orbital* orbital = m_orbitals[i];
        for(int j = 0; j < m_nParticlesHalf; j++) {
            tmpMatrix(i,j) = orbital->evaluate(positions, j);
        }
    }
    return tmpMatrix;
}
