#include <QCoreApplication>
#include <QDebug>
#include "manager.h"
#include <QThread>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QThread::currentThread()->setObjectName("Main");

    manager m;
    m.start();

    return a.exec();
}
