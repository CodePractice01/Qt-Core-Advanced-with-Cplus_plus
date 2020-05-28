#include "test.h"


//QThread inherited it is NOT the correct way to do it

test::test(QObject *parent) : QThread(parent)
{

}

void test::quit()
{
    ok = false;
    QThread::quit();
}

void test::run()
{
    ok = true;
    for(int  i=0;i < 1000 ; i++)
    {
        qInfo() << i;
        this->sleep(1); //1second
        // this is bad because now code become unpredictable
        //control can come from anywhere

        if(!ok) break;
    }

    qInfo() << "Finished";

}
