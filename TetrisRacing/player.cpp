#include "player.h"
#include "car.h"

player::player(MainGame *w): QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap("D:/code/qt/game/car.png"));

    setPos(xOffset, yOffset);

    window = w;

}

player::~player()
{
    delete this;
}

void player::spawn()
{
    if(isPlayAble)
    {
            car * newCar = new car(window);
            connect(newCar, SIGNAL(stopGame()), this, SLOT(stopTheGame()));
            scene()->addItem(newCar);
            qDebug() << "Spawn";
    }
}

void player::resetPos()
{
    window->ui->deadText->setVisible(false);
    setPos(xOffset, yOffset);
    isPlayAble = true;
    window->ui->graphicsView->setFocus();
    setFocus();
    isRight = true;
    window->ui->score->setText("0");
    window->scene->setSceneRect((scene()->sceneRect()));
    window->scene->setBackgroundBrush(QBrush(QImage("D:/code/qt/game/bg.png")));
}

void player::stopTheGame()
{
    isPlayAble = false;
    window->ui->deadText->setVisible(true);
}

void player::keyPressEvent(QKeyEvent *key)
{
    if(isPlayAble)
    {
        if(key->key() == Qt::Key_A)
        {
            if(isRight)
            {
                setPos(-(xOffset + 120), y());
                isRight = false;
            }
        }
        if(key->key() == Qt::Key_D)
        {
            if(!isRight)
            {
                setPos(xOffset, y());
                isRight = true;
            }
        }
        if((key->key() == Qt::Key_W) && (y() > (-(window->ui->graphicsView->height() / 2) + 10)))
        {
            setPos(x(), y() - 10);
        }
        if(key->key() == Qt::Key_S && (y() < (window->ui->graphicsView->height() / 2 - hei - 10)))
        {
            setPos(x(), y() + 10);
        }
    }
}
