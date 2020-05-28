#include "manager.h"

manager::manager(QObject *parent) : QObject(parent)
{
    for(int i=0; i< 5;i++)
    {
        QThread* thread =  new QThread(this);
        thread-> setObjectName("Thread " + QString::number(i));

        qInfo() << "Created: " << thread->objectName();

        connect(thread, &QThread::started, this, &manager::started);
        connect(thread, &QThread::finished, this, &manager::finished);

        threads.append(thread);

    }
}

void manager::start()
{
    qInfo()<< "Starting..";
    foreach (QThread* thread, threads) {
       qInfo() << "Starting " << thread->objectName();
       //create a new counter
       counter* c = new counter(); // no parents

      //move it to the thread
       c->moveToThread(thread);

        // c->start(); //Single thread!

       connect(thread, &QThread::start, c, &counter::start);

       //start each thread after it;s connecter the signals and slots
       thread->start();
    }
}

void manager::started()
{
    QThread* thread = qobject_cast<QThread*>(sender());
     if(!thread) return;
    qInfo()<< "Started  " << thread->objectName();
}

void manager::finished()
{
    QThread* thread = qobject_cast<QThread*>(sender());
     if(!thread) return;
     qInfo()<< "Finished " << thread->objectName();
}
