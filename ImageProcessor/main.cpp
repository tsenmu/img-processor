#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen ss(QPixmap::fromImage(QImage(":/images/splash_screen.png")));
    ss.show();
    MainWindow w;

    w.show();

    return a.exec();
}
