#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QThread>
#include <QRunnable>
#include <QDebug>
#include <QRandomGenerator>
#include <QMutex>
#include <QMutexLocker>
#include "counter.h"

class worker : public QObject
{
    Q_OBJECT
public:
    explicit worker(QObject *parent = nullptr, Counter* counter = nullptr, QMutex* mutex =nullptr);
    void run();
signals:

public slots:

private:

    Counter* counter;
    QMutex* mutex;

};

#endif // WORKER_H
