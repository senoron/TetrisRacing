#ifndef MAINGAME_H
#define MAINGAME_H

#include "libraries.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainGame; }
QT_END_NAMESPACE

class MainGame : public QMainWindow
{
    Q_OBJECT

public:
    MainGame(QWidget *parent = nullptr);
    ~MainGame();
    QGraphicsScene * scene = new QGraphicsScene();
    void addToScene(QGraphicsObject * r);
    Ui::MainGame *ui;

signals:
    void resetPlayerPos();

private slots:

    void on_pushRestart_released();
private:

    int xOffset = 20;
    int yOffsey = 50;
    int spawnRate = 1000; //in miliseconds;
    int viewW = 370;
    int viewH = 560;
    QTimer * timer;

};

#endif // MAINGAME_H
