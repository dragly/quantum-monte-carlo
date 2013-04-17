#include <QString>
#include <QtTest>

class SimpleWaveFunctionTest : public QObject
{
    Q_OBJECT
    
public:
    SimpleWaveFunctionTest();
    
private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
};

SimpleWaveFunctionTest::SimpleWaveFunctionTest()
{
}

void SimpleWaveFunctionTest::initTestCase()
{
}

void SimpleWaveFunctionTest::cleanupTestCase()
{
}

void SimpleWaveFunctionTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(SimpleWaveFunctionTest)

#include "tst_simplewavefunctiontest.moc"
