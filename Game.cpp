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
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
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

void Game::start()
{
    // clear the scene
    scene->clear();

    // set background image
    setBackgroundBrush(QBrush(QImage(":/IMAGE/Images/menu.png")));

    // map 1
    Button* map1 = new Button(QString("Map 1"));
    int m1xPos = this->width()/2 - map1->boundingRect().width()/2;
    int m1yPos = 275;
    map1->setPos(m1xPos,m1yPos);
    connect(map1,SIGNAL(clicked()),this,SLOT(Map_1()));
    scene->addItem(map1);

    // map 2
    Button* map2 = new Button(QString("Map 2"));
    int m2xPos = this->width()/2 - map2->boundingRect().width()/2;
    int m2yPos = 350;
    map2->setPos(m2xPos,m2yPos);
    connect(map2,SIGNAL(clicked()),this,SLOT(Map_2()));
    scene->addItem(map2);

    // map 3
    Button* map3 = new Button(QString("Map 3"));
    int m3xPos = this->width()/2 - map3->boundingRect().width()/2;
    int m3yPos = 425;
    map3->setPos(m3xPos,m3yPos);
    connect(map3,SIGNAL(clicked()),this,SLOT(Map_3()));
    scene->addItem(map3);

    //setBackgroundBrush(QBrush(Qt::NoBrush));
    //mapCreator map;
    //map.creataMap(scene, "3");
}

void Game::newTank()
{
    std::cout << "HELLO";
}

void Game::Map_1()
{
    // clear scene
    scene->clear();

    // craete the map
    setBackgroundBrush(QBrush(Qt::NoBrush));
    MapCreator map;
    map.creataMap(scene, "1");
}

void Game::Map_2()
{
    // clear scene
    scene->clear();

    // craete the map
    setBackgroundBrush(QBrush(Qt::NoBrush));
    MapCreator map;
    map.creataMap(scene, "2");
}

void Game::Map_3()
{
    // clear scene
    scene->clear();

    // craete the map
    setBackgroundBrush(QBrush(Qt::NoBrush));
    MapCreator map;
    map.creataMap(scene, "3");
}
