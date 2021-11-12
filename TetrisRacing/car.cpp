#include "car.h"
#include "player.h"
#include "maingame.h"

car::car(MainGame *w): QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap("D:/code/qt/game/car.png"));

    int randomPosition = rand() % 2;

    if(randomPosition){setPos(xOffset, -(viewH/2 + hei));}
    if(!randomPosition){setPos(-(xOffset + wid), -(viewH/2 + hei));}

    window = w;

    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(100);
}

car::~car()
{
    delete timer;

}

void car::move()
{
        QList<QGraphicsItem *> colliding = collidingItems();
        int count = colliding.size();
        for(int i = 0; i < count; i++)
        {
            if(typeid(*(colliding[i])) == typeid(player))
            {
                scene()->removeItem(this);
                emit stopGame();
                delete this;
                return;
            }
        }

        setPos(x(), y() + carSpeed);
        if(pos().y() > viewH/2)
        {
           scene()->removeItem(this);
           int number = window->ui->score->text().toInt();
           number++;

           window->ui->score->setText(QString::number(number));
           delete this;
        }
}
