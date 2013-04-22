#include <iostream>
#include <iomanip>

#include <src/wavefunction/wavefunction.h>

#include <unittest++/UnitTest++.h>

using namespace std;
class DummyWaveFunction : public WaveFunction {
public:
    DummyWaveFunction(int nParticles, int nDimensions, int nParameters) : WaveFunction(nParticles, nDimensions, nParameters) {
    }
    double evaluate(const mat &positions) {
        double evaluation = 0;
        for(int i = 0; i < m_nParticles; i++) {
            evaluation += dot(positions.row(i), positions.row(i));
        }
        return evaluation;
    }
};

TEST(testEvaluationRatio)
{
    DummyWaveFunction wf(2,3,3);
    mat positions = { 1,2,3,4,5,6 };
    positions.reshape(2,3);
    wf.setNextPositions(positions);
    wf.initialize();

    mat positions2 = { 2,3,4,5,6,7 };
    positions2.reshape(2,3);
    wf.setNextPositions(positions2);
    wf.updateNextEvaluation();

    CHECK(fabs(wf.evaluationRatio() - 1.5274725274725274) < 1e-6);
}

TEST(testNumericalGradient) {
    DummyWaveFunction wf(2,3,3);
    mat positions = { 1,2,3,4,5,6 };
    positions.reshape(2,3);
    wf.setNextPositions(positions);
    wf.initialize();
    wf.updateNextGradientNumerically();

    mat correctGradient = {2,4,6,8,10,12};
    correctGradient.reshape(2,3);

    mat difference = abs(wf.nextGradient() - correctGradient);

    CHECK(difference.min() < 1e-4);
}

TEST(testNumericalLaplace) {
    DummyWaveFunction wf(2,3,3);
    mat positions = { 1,2,3,4,5,6 };
    positions.reshape(2,3);
    wf.setNextPositions(positions);
    wf.initialize();
    wf.updateNextLaplaceNumerically();

    CHECK(fabs(wf.nextLaplace() - 12) < 1e-4);
}

int main()
{
    return UnitTest::RunAllTests();
}

