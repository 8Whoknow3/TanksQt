#include "Game.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <iostream>
#include <Button.h>
#include <QBrush>
#include <MapCreator.h>


Game::Game(QGraphicsView *parent)
    : QGraphicsView{parent}
{
    setFixedSize(1350,700);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1350,700);
    setScene(scene);

    // set background image
    setBackgroundBrush(QBrush(QImage(":/IMAGE/Images/gamemenu.png")));
}

void Game::displayMainMenu()
{
    // create the title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Tanks War"));
    QFont titleFont("times",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // create the play button
    Button* playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(Smap()));
    scene->addItem(playButton);

    // create the NewTank button
    Button* NewTankButton = new Button(QString("NewTank"));
    int pxPos = this->width()/2 - NewTankButton->boundingRect().width()/2;
    int pyPos = 350;
    NewTankButton->setPos(pxPos,pyPos);
    connect(NewTankButton,SIGNAL(clicked()),this,SLOT(newTank()));
    scene->addItem(NewTankButton);

    // create the quit button
    Button* quitButton = new Button(QString("Exit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 425;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);
}

void Game::Smap()
{
    // clear the scene
    scene->clear();

    // set background image
    setBackgroundBrush(QBrush(QImage(":/IMAGE/Images/menu.png")));

    // create the title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Select Map"));
    QFont titleFont("times",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 100;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // map 1
    Button* map1 = new Button(QString("Map 1"));
    int m1xPos = this->width()/2 - map1->boundingRect().width()/2;
    int m1yPos = 275;
    map1->setPos(m1xPos,m1yPos);
    connect(map1,SIGNAL(clicked()),this,SLOT(SMT1()));
    scene->addItem(map1);

    // map 2
    Button* map2 = new Button(QString("Map 2"));
    int m2xPos = this->width()/2 - map2->boundingRect().width()/2;
    int m2yPos = 350;
    map2->setPos(m2xPos,m2yPos);
    connect(map2,SIGNAL(clicked()),this,SLOT(SMT2()));
    scene->addItem(map2);

    // map 3
    Button* map3 = new Button(QString("Map 3"));
    int m3xPos = this->width()/2 - map3->boundingRect().width()/2;
    int m3yPos = 425;
    map3->setPos(m3xPos,m3yPos);
    connect(map3,SIGNAL(clicked()),this,SLOT(SMT3()));
    scene->addItem(map3);
}

void Game::newTank()
{
    std::cout << "HELLO";
}

void Game::SMT1()
{
    M = 1;

    // clear the scene
    scene->clear();

    // create the title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Select Tank P1"));
    QFont titleFont("times",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 100;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // speed
    Button* Speed = new Button(QString("Speed"));
    int sxPos = this->width()/2 - Speed->boundingRect().width()/2;
    int syPos = 275;
    Speed->setPos(sxPos,syPos);
    connect(Speed,SIGNAL(clicked()),this,SLOT(T1()));
    scene->addItem(Speed);

    // speed
    Button* Balance = new Button(QString("Balance"));
    int bxPos = this->width()/2 - Balance->boundingRect().width()/2;
    int byPos = 350;
    Balance->setPos(bxPos,byPos);
    connect(Balance,SIGNAL(clicked()),this,SLOT(T2()));
    scene->addItem(Balance);

    // strength
    Button* Strength = new Button(QString("Strength"));
    int SxPos = this->width()/2 - Strength->boundingRect().width()/2;
    int SyPos = 425;
    Strength->setPos(SxPos,SyPos);
    connect(Strength,SIGNAL(clicked()),this,SLOT(T3()));
    scene->addItem(Strength);
}

void Game::SMT2()
{
    M = 2;

    // clear the scene
    scene->clear();

    // create the title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Select Tank P1"));
    QFont titleFont("times",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 100;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // speed
    Button* Speed = new Button(QString("Speed"));
    int sxPos = this->width()/2 - Speed->boundingRect().width()/2;
    int syPos = 275;
    Speed->setPos(sxPos,syPos);
    connect(Speed,SIGNAL(clicked()),this,SLOT(T1()));
    scene->addItem(Speed);

    // speed
    Button* Balance = new Button(QString("Balance"));
    int bxPos = this->width()/2 - Balance->boundingRect().width()/2;
    int byPos = 350;
    Balance->setPos(bxPos,byPos);
    connect(Balance,SIGNAL(clicked()),this,SLOT(T2()));
    scene->addItem(Balance);

    // strength
    Button* Strength = new Button(QString("Strength"));
    int SxPos = this->width()/2 - Strength->boundingRect().width()/2;
    int SyPos = 425;
    Strength->setPos(SxPos,SyPos);
    connect(Strength,SIGNAL(clicked()),this,SLOT(T3()));
    scene->addItem(Strength);
}

void Game::SMT3()
{
    M = 3;

    // clear the scene
    scene->clear();

    // create the title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Select Tank P1"));
    QFont titleFont("times",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 100;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // speed
    Button* Speed = new Button(QString("Speed"));
    int sxPos = this->width()/2 - Speed->boundingRect().width()/2;
    int syPos = 275;
    Speed->setPos(sxPos,syPos);
    connect(Speed,SIGNAL(clicked()),this,SLOT(T1()));
    scene->addItem(Speed);

    // speed
    Button* Balance = new Button(QString("Balance"));
    int bxPos = this->width()/2 - Balance->boundingRect().width()/2;
    int byPos = 350;
    Balance->setPos(bxPos,byPos);
    connect(Balance,SIGNAL(clicked()),this,SLOT(T2()));
    scene->addItem(Balance);

    // strength
    Button* Strength = new Button(QString("Strength"));
    int SxPos = this->width()/2 - Strength->boundingRect().width()/2;
    int SyPos = 425;
    Strength->setPos(SxPos,SyPos);
    connect(Strength,SIGNAL(clicked()),this,SLOT(T3()));
    scene->addItem(Strength);
}

void Game::T1()
{
    Tank1 = 1;

    // clear the scene
    scene->clear();

    // create the title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Select Tank P2"));
    QFont titleFont("times",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 100;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // speed
    Button* Speed = new Button(QString("Speed"));
    int sxPos = this->width()/2 - Speed->boundingRect().width()/2;
    int syPos = 275;
    Speed->setPos(sxPos,syPos);
    connect(Speed,SIGNAL(clicked()),this,SLOT(TT1()));
    scene->addItem(Speed);

    // speed
    Button* Balance = new Button(QString("Balance"));
    int bxPos = this->width()/2 - Balance->boundingRect().width()/2;
    int byPos = 350;
    Balance->setPos(bxPos,byPos);
    connect(Balance,SIGNAL(clicked()),this,SLOT(TT2()));
    scene->addItem(Balance);

    // strength
    Button* Strength = new Button(QString("Strength"));
    int SxPos = this->width()/2 - Strength->boundingRect().width()/2;
    int SyPos = 425;
    Strength->setPos(SxPos,SyPos);
    connect(Strength,SIGNAL(clicked()),this,SLOT(TT3()));
    scene->addItem(Strength);
}

void Game::T2()
{
    Tank1 = 2;

    // clear the scene
    scene->clear();

    // create the title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Select Tank P2"));
    QFont titleFont("times",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 100;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // speed
    Button* Speed = new Button(QString("Speed"));
    int sxPos = this->width()/2 - Speed->boundingRect().width()/2;
    int syPos = 275;
    Speed->setPos(sxPos,syPos);
    connect(Speed,SIGNAL(clicked()),this,SLOT(TT1()));
    scene->addItem(Speed);

    // speed
    Button* Balance = new Button(QString("Balance"));
    int bxPos = this->width()/2 - Balance->boundingRect().width()/2;
    int byPos = 350;
    Balance->setPos(bxPos,byPos);
    connect(Balance,SIGNAL(clicked()),this,SLOT(TT2()));
    scene->addItem(Balance);

    // strength
    Button* Strength = new Button(QString("Strength"));
    int SxPos = this->width()/2 - Strength->boundingRect().width()/2;
    int SyPos = 425;
    Strength->setPos(SxPos,SyPos);
    connect(Strength,SIGNAL(clicked()),this,SLOT(TT3()));
    scene->addItem(Strength);
}

void Game::T3()
{
    Tank1 = 3;

    // clear the scene
    scene->clear();

    // create the title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Select Tank P2"));
    QFont titleFont("times",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 100;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // speed
    Button* Speed = new Button(QString("Speed"));
    int sxPos = this->width()/2 - Speed->boundingRect().width()/2;
    int syPos = 275;
    Speed->setPos(sxPos,syPos);
    connect(Speed,SIGNAL(clicked()),this,SLOT(TT1()));
    scene->addItem(Speed);

    // speed
    Button* Balance = new Button(QString("Balance"));
    int bxPos = this->width()/2 - Balance->boundingRect().width()/2;
    int byPos = 350;
    Balance->setPos(bxPos,byPos);
    connect(Balance,SIGNAL(clicked()),this,SLOT(TT2()));
    scene->addItem(Balance);

    // strength
    Button* Strength = new Button(QString("Strength"));
    int SxPos = this->width()/2 - Strength->boundingRect().width()/2;
    int SyPos = 425;
    Strength->setPos(SxPos,SyPos);
    connect(Strength,SIGNAL(clicked()),this,SLOT(TT3()));
    scene->addItem(Strength);
}

void Game::TT1()
{
    Tank2 = 1;

    // clear the scene
    scene->clear();

    // Start The Game
    Button* STG = new Button(QString("Start The Game"));
    int xPos = this->width()/2 - STG->boundingRect().width()/2;
    int yPos = 350;
    STG->setPos(xPos,yPos);
    connect(STG,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(STG);
}

void Game::TT2()
{
    Tank2 = 2;

    // clear the scene
    scene->clear();

    // Start The Game
    Button* STG = new Button(QString("Start The Game"));
    int xPos = this->width()/2 - STG->boundingRect().width()/2;
    int yPos = 350;
    STG->setPos(xPos,yPos);
    connect(STG,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(STG);
}

void Game::TT3()
{
    Tank2 = 3;

    // clear the scene
    scene->clear();

    // Start The Game
    Button* STG = new Button(QString("Start The Game"));
    int xPos = this->width()/2 - STG->boundingRect().width()/2;
    int yPos = 350;
    STG->setPos(xPos,yPos);
    connect(STG,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(STG);
}

void Game::start()
{
    // clear the scene
    scene->clear();

    // create the map
    setBackgroundBrush(QBrush(Qt::NoBrush));
    MapCreator map;
    map.creataMap(scene, M);

    // create the Tanks
    P1 = new Tank(1, Tank1);
    P2 = new Tank(2, Tank2);

    if( M == 1 ){
        P1->setPos(80, 625);
        P2->setPos(1250, 625);
    }
    else if( M == 2 ){
        P1->setPos(80, 130);
        P2->setPos(1275, 130);
    }
    else if( M == 3 ){
        P1->setPos(80, 130);
        P2->setPos(1275, 625);
    }

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), P1, SLOT(TankMove2()));
    connect(timer, SIGNAL(timeout()), P2, SLOT(TankMove1()));
    timer->start(1000 / 50);

    scene->addItem(P1);
    scene->addItem(P2);
}
