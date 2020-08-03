#include "initapp.h"

InitApp::InitApp(QWindow *parent) :
    QQuickView(parent),
    m_comThread(new QThread(this))
{
    QThread::currentThread()->setObjectName("MainThread");
    m_comThread->setObjectName("ComThread");

    qDebug() << Q_FUNC_INFO << QThread::currentThread();

    m_comManager = new ComManager();
    m_comManager->moveToThread(m_comThread);
    connect(m_comThread, SIGNAL(started()), m_comManager, SLOT(startTimer()));
    connect(m_comThread, SIGNAL(started()), this, SLOT(setQmlSource()));
    m_comThread->start();
}

void InitApp::setQmlSource()
{
    setSource(QUrl("qrc:/main.qml"));
    show();
}
