#ifndef SLATER_H
#define SLATER_H

#include <vector>
#include <armadillo>

using namespace std;
using namespace arma;

class Orbital;

class Slater
{
public:
    Slater(int nParticles, bool isSpinUp);

    double evaluateDeterminant(const mat& positions);
    const mat evaluateMatrix(const mat& positions);
    void setOrbitals(const vector<Orbital*>& orbitals);

protected:
    vector<Orbital*> m_orbitals;
    int m_nParticles;
    int m_nParticlesHalf;
    bool m_isSpinUp;
    int indexOffset;
};

inline void Slater::setOrbitals(const vector<Orbital *> &orbitals) {
    m_orbitals = orbitals;
}

#endif // SLATER_H
