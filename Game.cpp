#include "Game.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <iostream>



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
    connect(playButton,SIGNAL(clicked()),this,SLOT(selector()));
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

void Game::selector()
{
    // clear the scene
    scene->clear();

    // set background image
    setBackgroundBrush(QBrush(QImage(":/IMAGE/Images/menu.png")));

    // Select Map
    QStringList Maps;
    Maps << tr("Map_1") << tr("Map_2") << tr("Map_3");

    bool ok;
    QString Map = QInputDialog::getItem(this, tr("Map Select"), tr("Maps"), Maps, 0, false, &ok);

    // Save the Map
    for(int i = 1; i <= 3; i++){
        if( Map == ("Map_" + QString::number(i)))
            M = i;
    }

    // Get Tanks Type from .txt file
    QList <QString > Tanksname;
    QStringList TanksType;
    QFile file(":/Info/Tanks/TanksInfo.txt");

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    while(!in.atEnd()){
        QString line = in.readLine();
        Tanksname.push_back(line);
    }

    for(int i = 0; i < Tanksname.size(); i++)
        TanksType << Tanksname[i];

    // Get Players Info
    // Player 1
    Player1 = QInputDialog::getText(this, tr("Players Name"), tr("P1"), QLineEdit::Normal, QDir::home().dirName(), &ok);
    Tank1 = QInputDialog::getItem(this, tr("Tanks Select"), tr("P1"), TanksType, 0, false, &ok);

    // Player 2
    Player2 = QInputDialog::getText(this, tr("Players Name"), tr("P2"), QLineEdit::Normal, QDir::home().dirName(), &ok);
    Tank2 = QInputDialog::getItem(this, tr("Tanks Select"), tr("P2"), TanksType, 0, false, &ok);

    // Start the Game
    Button* Start = new Button(QString("Start the Game"));
    int sxPos = this->width()/2 - Start->boundingRect().width()/2;
    int syPos = 350;
    Start->setPos(sxPos,syPos);
    connect(Start,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(Start);
}

void Game::newTank()
{
    QFile file(":/Info/Tanks/TanksInfo.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        std::cout << "ali";
        return;
    }
    QTextStream out(&file);
    out << "The magic number is: " << 49 << "\n";


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
    P1 = new Tank(Player1, Tank1);
    P2 = new Tank(Player2, Tank2);

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
    timer->start(20);

    scene->addItem(P1);
    scene->addItem(P2);

    // Health
    P1->health1->setPos(1100, 0);
    scene->addItem(P1->health1);
    P2->health2->setPos(0, 0);
    scene->addItem(P2->health2);
}
