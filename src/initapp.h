#ifndef INITAPP_H
#define INITAPP_H

#include <QObject>
#include <QQuickView>
#include <QThread>

#include "commanager.h"

class InitApp : public QQuickView
{
    Q_OBJECT

public:
    InitApp(QWindow *parent = Q_NULLPTR);

private:
    QThread *m_comThread;
    ComManager *m_comManager;

private slots:
    void setQmlSource();
};

#endif // INITAPP_H
