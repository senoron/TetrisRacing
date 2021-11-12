#ifndef CAR_H
#define CAR_H

#include "libraries.h"
#include "maingame.h"
#include "ui_maingame.h"

class car: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    car(MainGame *w);
    ~car();

signals:
    void stopGame();

private:
    int xOffset = 20;
    int wid = 120;
    int hei = 170;
    int viewW = 370;
    int viewH = 560;
    int carSpeed = 70;

    bool isPlayAble = true;

    MainGame *window;
    QTimer * timer;

    void stopTheGame();
public slots:
    void move();
};

#endif // CAR_H
