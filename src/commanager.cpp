#include "commanager.h"

ComManager::ComManager(QObject * const parent) :
    QObject(parent),
    m_timer(new QTimer(this))
{
    qDebug() << Q_FUNC_INFO << QThread::currentThread();
}

void ComManager::startTimer()
{
    m_timer->setInterval(1000); // in the real application every 10 ms
    connect(m_timer, SIGNAL(timeout()), this, SLOT(processData()));
    qDebug() << Q_FUNC_INFO << QThread::currentThread() << "m_timer" << m_timer;
    m_timer->start();
}

void ComManager::processData()
{
    qDebug() << Q_FUNC_INFO << QThread::currentThread() << "m_timer" << m_timer;
}
