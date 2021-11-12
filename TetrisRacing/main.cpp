#include "maingame.h"

#include <QApplication>
#include <QTimer>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainGame w;

    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap("D:/code/qt/game/splash.png"));
    splash->show();

    QTimer::singleShot(2500, splash, SLOT(close()));
    QTimer::singleShot(2500, &w, SLOT(show()));
    QTimer::singleShot(3000, &w, SIGNAL(resetPlayerPos()));

    //w.show();

    return a.exec();
}
