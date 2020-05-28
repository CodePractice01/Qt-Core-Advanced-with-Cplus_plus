#include "test.h"

test::test(QObject *parent) : QObject(parent)
{

}

void test::timeout()
{
    qInfo() << QDateTime::currentDateTime().toString() << " on " << QThread::currentThread();

}

void test::start()
{
    //connect the timer to the signal slot
    connect(&timer, &QTimer::timeout, this, &test::timeout);
    timer.setInterval(1000);
    timer.start();

}
