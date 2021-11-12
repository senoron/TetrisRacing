#include "maingame.h"
#include "ui_maingame.h"
#include "car.h"
#include "player.h"

MainGame::MainGame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainGame)
{
    ui->setupUi(this);

    setWindowTitle("Tetris Racing");

    scene->setBackgroundBrush(QBrush(QImage("D:/code/qt/game/bg.png")));

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene->setSceneRect((scene->sceneRect()));

    scene->addLine(0,-(ui->graphicsView->height()/2 - 5),0,ui->graphicsView->height()/2 - 5,QPen(Qt::transparent));
    scene->setSceneRect((scene->sceneRect()));

    player * mainPlayer = new player(this);
    mainPlayer->setFlag(QGraphicsItem::ItemIsFocusable);
    mainPlayer->setFocus();

    scene->addItem(mainPlayer);

    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), mainPlayer, SLOT(spawn()));
    timer->start(spawnRate);


    ui->graphicsView->setScene(scene);

    connect(this, SIGNAL(resetPlayerPos()), mainPlayer, SLOT(resetPos()));

    ui->deadText->setVisible(false);
}

MainGame::~MainGame()
{
    delete ui;
    delete timer;
}

void MainGame::addToScene(QGraphicsObject *r)
{
    scene->addItem(r);
}


void MainGame::on_pushRestart_released()
{
    ui->deadText->setVisible(false);
    emit resetPlayerPos();
}
