#ifndef WAVEFUNCTION_H
#define WAVEFUNCTION_H

#include <armadillo>

using namespace arma;

class WaveFunction
{
public:
    WaveFunction(int nParticles, int nDimensions, int nVariationalParameters);

    virtual double evaluate(const mat& positions) = 0;
    virtual void updateNextEvaluation();
    virtual void updateNextGradient();
    virtual void updateNextLaplace();

    virtual void updateNextLaplaceNumerically();
    virtual void updateNextGradientNumerically();

    virtual const mat &nextGradient() const;
    virtual double nextLaplace() const;
    virtual double nextEvaluation() const;
    virtual double evaluationRatio() const;
    virtual double currentEvaluation() const;

    virtual void setNextPosition(int particleNumber, const vec& position);
    virtual void setNextPositions(const mat& positions);
    virtual void setVariationalParameters(const vec& parameters);
    virtual void setVariationalParameter(int parameterNumber, double parameterValue);

    virtual void rejectNext();
    virtual void acceptNext();

    virtual void initialize();

protected:
    int m_nParticles;
    int m_nDimensions;
    int m_nVariationalParameters;
    mat m_currentPositions;
    mat m_nextPositions;
    vec m_variationalParameters;

    mat m_nextGradient; // matrix of shape nParticles * nDimensions
//    vec m_currentGradient;
    double m_nextLaplace;
//    double m_currentLaplace;

    double m_nextEvaluation;
    double m_currentEvaluation;

    double m_numericalDifferenceStep;
    double m_numericalDifferenceStepSquared;
};

inline void WaveFunction::setNextPosition(int particleNumber, const vec &position) {
    m_nextPositions.row(particleNumber) = position.t();
}

inline void WaveFunction::setNextPositions(const mat &positions) {
    m_nextPositions = positions;
}

inline void WaveFunction::setVariationalParameter(int parameterNumber, double parameterValue) {
    m_variationalParameters(parameterNumber) = parameterValue;
}

inline void WaveFunction::setVariationalParameters(const vec &parameters) {
    m_variationalParameters = parameters;
}

inline double WaveFunction::nextEvaluation() const {
    return m_nextEvaluation;
}

inline double WaveFunction::currentEvaluation() const {
    return m_currentEvaluation;
}

inline const mat& WaveFunction::nextGradient() const {
    return m_nextGradient;
}

inline double WaveFunction::nextLaplace() const {
    return m_nextLaplace;
}

#endif // WAVEFUNCTION_H
