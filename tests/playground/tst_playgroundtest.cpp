#include <QString>
#include <QtTest>

#include <iostream>
#include <iomanip>

#include <src/wavefunction/wavefunction.h>

using namespace std;

bool armaFuzzyCompare(mat matrix1, mat matrix2) {
    umat comparison = ((matrix1 + 1e-2 > matrix2) + (matrix1 - 1e-2 < matrix2));
    if(comparison.min() < 2) {
        return false;
    }
    return true;
}

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

class PlaygroundTest : public QObject
{
    Q_OBJECT
    
public:
    PlaygroundTest();


private Q_SLOTS:
    void testEvaluationRatio();
    void testNumericalGradient();
    void testNumericalLaplace();
};

PlaygroundTest::PlaygroundTest()
{
}

void PlaygroundTest::testEvaluationRatio()
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

    QVERIFY2(fabs(wf.evaluationRatio() - 1.5274725274725274) < 1e-6, "Error!");
}

void PlaygroundTest::testNumericalGradient() {
    DummyWaveFunction wf(2,3,3);
    mat positions = { 1,2,3,4,5,6 };
    positions.reshape(2,3);
    wf.setNextPositions(positions);
    wf.initialize();

    mat correctGradient = {2,4,6,8,10,12};
    correctGradient.reshape(2,3);

    mat difference = abs(wf.nextGradient() - correctGradient);

    QVERIFY2(difference.min() < 1e-4, "Failure!");
}

void PlaygroundTest::testNumericalLaplace() {
    DummyWaveFunction wf(2,3,3);
    mat positions = { 1,2,3,4,5,6 };
    positions.reshape(2,3);
    wf.setNextPositions(positions);
    wf.initialize();

    QVERIFY2(fabs(wf.nextLaplace() - 12) < 1e-4, "Failure!");
}

QTEST_APPLESS_MAIN(PlaygroundTest)

#include "tst_playgroundtest.moc"
