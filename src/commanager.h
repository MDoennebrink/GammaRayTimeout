#ifndef COMMANAGER_H
#define COMMANAGER_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QThread>

class ComManager : public QObject
{
    Q_OBJECT

public:
    ComManager(QObject * const parent = Q_NULLPTR);

public slots:
    void startTimer();

private:
    QTimer *m_timer;

private slots:
    void processData();
};

#endif // COMMANAGER_H
