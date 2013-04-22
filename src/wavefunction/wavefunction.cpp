#include "wavefunction.h"

WaveFunction::WaveFunction(int nParticles, int nDimensions, int nVariationalParameters) :
    m_nParticles(nParticles),
    m_nDimensions(nDimensions),
    m_nVariationalParameters(nVariationalParameters),
    m_currentPositions(zeros(nParticles, nDimensions)),
    m_nextPositions(zeros(nParticles, nDimensions)),
    m_nextGradient(zeros(nParticles, nDimensions)),
    m_nextLaplace(0),
    m_numericalDifferenceStep(0.0001),
    m_numericalDifferenceStepSquared(m_numericalDifferenceStep*m_numericalDifferenceStep)
{
}

void WaveFunction::updateNextEvaluation()
{
    m_nextEvaluation = evaluate(m_nextPositions);
}

void WaveFunction::updateNextGradient()
{
    updateNextGradientNumerically();
}

void WaveFunction::updateNextLaplace() {
    updateNextLaplaceNumerically();
}


void WaveFunction::updateNextGradientNumerically() {
    double h = m_numericalDifferenceStep;
    mat positionsPlus = m_nextPositions;
    mat positionsMinus = m_nextPositions;
    for(int i = 0; i < m_nParticles; i++) {
        for(int j = 0; j < m_nDimensions; j++) {
            positionsPlus(i,j) = m_nextPositions(i,j) + h;
            positionsMinus(i,j) = m_nextPositions(i,j) - h;
            m_nextGradient(i,j) = (evaluate(positionsPlus) - evaluate(positionsMinus)) / (2 * h);
            positionsPlus(i,j) = m_nextPositions(i,j);
            positionsMinus(i,j) = m_nextPositions(i,j);
        }
    }
}

void WaveFunction::updateNextLaplaceNumerically() {
    double h = m_numericalDifferenceStep;
    double hSquared = m_numericalDifferenceStepSquared;
    mat positionsPlus = m_nextPositions;
    mat positionsMinus = m_nextPositions;
    double laplace = 0;
    for(int i = 0; i < m_nParticles; i++) {
        for(int j = 0; j < m_nDimensions; j++) {
            positionsPlus(i,j) = m_nextPositions(i,j) + h;
            positionsMinus(i,j) = m_nextPositions(i,j) - h;
            laplace += (evaluate(positionsPlus) - 2 * evaluate(m_nextPositions) + evaluate(positionsMinus)) / hSquared;
            positionsPlus(i,j) = m_nextPositions(i,j);
            positionsMinus(i,j) = m_nextPositions(i,j);
        }
    }
    m_nextLaplace = laplace;
}

double WaveFunction::evaluationRatio() const {
    return m_nextEvaluation / m_currentEvaluation;
}


void WaveFunction::rejectNext()
{
    m_nextPositions = m_currentPositions;
    m_nextGradient.zeros(); // current - zero for debug until needed
    m_nextLaplace = 0; // current - zero for debug until needed
    m_nextEvaluation = m_currentEvaluation;
}

void WaveFunction::acceptNext()
{
    m_currentPositions = m_nextPositions;
    m_currentEvaluation = m_nextEvaluation;
    // m_currentGradient = m_nextGradient;
    // m_currentLaplace = m_nextLaplace;
}

void WaveFunction::initialize()
{
    updateNextEvaluation();
    updateNextGradient();
    updateNextLaplace();
    acceptNext();
}
