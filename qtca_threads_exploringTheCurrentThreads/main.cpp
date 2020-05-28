#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include <QDateTime>


//threads control the execution, thinks of a thread as "time on the CPU"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "App Thread" << a.thread();
    qInfo() << "Current Thread " << QThread::currentThread();

    Q_ASSERT(a.thread() == QThread::currentThread());

    qInfo() << "Running" << QThread::currentThread() -> isRunning();
    qInfo() << "LoopLevel" << QThread::currentThread() -> loopLevel();
    qInfo() << "stackSize" << QThread::currentThread() -> stackSize();
    qInfo() << "isFinished?" << QThread::currentThread() -> isFinished();
    qInfo() << "Before" << QDateTime::currentDateTime().toString();
    //dellay 5 seconds
    QThread::sleep(5);
    qInfo() << "After" << QDateTime::currentDateTime().toString();


    return a.exec();
}
