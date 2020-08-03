#include <QGuiApplication>
#include "initapp.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    InitApp initApp;
    return app.exec();
}
