#include <QCoreApplication>
#include <QTimer>
#include <QDebug>
#include <QThread>
#include <QSharedPointer>
#include "test.h"


//creating and using threads



static QSharedPointer<QThread> sptr;
void timeout()
{
    if (!sptr.isNull())
    {
        qInfo() << "Time out - stopping other thread from " <<  QThread::currentThread();
        sptr.data()->quit();

    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

     qInfo() << "Application Thread " << a.thread();
    qInfo() << "Current Thread " << QThread::currentThread();

    test t;

    qInfo() << "Timer thread: " << t.thread();


    QThread thread;

    sptr.reset(&thread);

    t.moveToThread(&thread);
    qInfo() << "move - Timer thread: " << t.thread();

    t.start();

    qInfo() << "Thread State: " << thread.isRunning();

    thread.start();

    QTimer timer;
    timer.singleShot(5000, &timeout);


    return a.exec();
}
