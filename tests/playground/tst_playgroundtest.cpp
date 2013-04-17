#include <QString>
#include <QtTest>

#include <iostream>
#include <iomanip>

using namespace std;

class PlaygroundTest : public QObject
{
    Q_OBJECT
    
public:
    PlaygroundTest();


private Q_SLOTS:
};

PlaygroundTest::PlaygroundTest()
{
}

QTEST_APPLESS_MAIN(PlaygroundTest)

#include "tst_playgroundtest.moc"
