#ifndef PLAYER_H
#define PLAYER_H

#include "libraries.h"
#include "maingame.h"
#include "ui_maingame.h"

class player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT


public:
    player(MainGame *w);
    ~player();


public slots:
    void spawn();
    void stopTheGame();
    void resetPos();
    void keyPressEvent(QKeyEvent * key);

private:
    int wid = 120;
    int hei = 170;
    bool isLeft = false;
    bool isRight = true;
    int xOffset = 20;
    int yOffset = 50;

    bool isPlayAble = true;

    MainGame *window;

};

#endif // PLAYER_H
