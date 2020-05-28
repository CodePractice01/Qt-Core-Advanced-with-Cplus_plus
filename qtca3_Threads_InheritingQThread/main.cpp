#include <QCoreApplication>
#include <QTimer>
#include <QSharedPointer>
#include "test.h"


static QSharedPointer<test> sptr;

void timeout()
{
    if(!sptr.isNull())
    {
        qInfo() << "Timeout  Stopping  Thread";
        sptr.data()->quit();
    }
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //start threat
    test thread;
    sptr.reset(&thread);
    thread.start();

    QTimer timer;
    //start timer //single shout out after 5 seconds
    //after 5seconds call void timeout()   --pointer to test----  sptr.data()->quit();
    timer.singleShot(5000, &timeout);

    return a.exec();
}
