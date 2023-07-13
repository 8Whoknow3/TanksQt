#include "Game.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <iostream>
#include <QFile>
#include "Bullet.h"

Game::Game(QGraphicsView *parent)
    : QGraphicsView{parent}
{
    setFixedSize(1485, 770);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1485, 770);
    setScene(scene);
}

Game::~Game()
{
    delete map; Maps.clear();
    delete P1;  delete P2;
    delete timer;
}

void Game::displayMainMenu()
{
    // set background image
    setBackgroundBrush(QBrush(QImage(":/IMAGE/Images/gamemenu.png")));

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
    Maps.clear();
    Maps << tr("Map_1") << tr("Map_2") << tr("Map_3");

    bool ok;
    QString Map = QInputDialog::getItem(this, tr("Map Select"), tr("Maps"), Maps, 0, false, &ok);

    // Save the Map
    for(int i = 1; i <= 3; i++){
        if( Map == ("Map_" + QString::number(i)))
            M = i;
    }

    // Get Tanks Type from .txt file
    TanksType.clear();
    Tanksname.clear();
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
    file.close();

    start();
}

void Game::newTank()
{
    setBackgroundBrush(QBrush(QImage(":/IMAGE/Images/menu.png")));
    scene->clear();
    // Get Tanks name
    bool ok;
    QString TName = QInputDialog::getText(this, tr("New Tanks"), tr("Name"), QLineEdit::Normal, QDir::home().dirName(), &ok);

    GetInfo:
    // Get Speed, Damage, Health
    int S = QInputDialog::getInt(this, tr("New Tanks"), tr("Speed"), 5, 1, 10, 1, &ok);
    int D = QInputDialog::getInt(this, tr("New Tanks"), tr("Damage"), 15, 5, 35, 5, &ok);
    int H = QInputDialog::getInt(this, tr("New Tanks"), tr("Health"), 80, 65, 150, 5, &ok);
    if(!((S + D + H) / 3 >= 20 && (S + D + H) / 3 <= 45))
        goto GetInfo;
    // Should write in the GameFile
    // Cant write in File
    displayMainMenu();
}

void Game::start()
{
    // clear the scene
    scene->clear();

    // create the map
    setBackgroundBrush(QBrush(Qt::NoBrush));
    map = new MapCreator(scene, M);

    // create the Tanks
    P1 = new Tank(Player1, Tank1);
    P2 = new Tank(Player2, Tank2);

    if( M == 1 ){
        P1->setPos(100, 675);
        P1->angle = 180;
        P1->setRotation(P1->angle);
        P2->setPos(1375, 675);
        P2->angle = 180;
        P2->setRotation(P2->angle);
    }
    else if( M == 2 ){
        P1->setPos(140, 150);
        P2->setPos(1365, 150);
    }
    else if( M == 3 ){
        P1->setPos(115, 150);
        P2->setPos(1375, 675);
        P2->angle = 180;
        P2->setRotation(P2->angle);
    }
    scene->addItem(P1);
    scene->addItem(P2);

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), P1, SLOT(TankMove2()));
    connect(timer, SIGNAL(timeout()), P2, SLOT(TankMove1()));
    timer->start(20);

    // Bullet
    connect (P1,&Tank::SBullet,this, &Game::sBullet);
    connect (P2,&Tank::SBullet,this, &Game::sBullet);

    // Health
    P1->health1->setPos(1245, 0);
    scene->addItem(P1->health1);
    P2->health2->setPos(0, 0);
    scene->addItem(P2->health2);
    connect(P1->health1, &Health1::EndofGame, this, &Game::slotEndofGame);
    connect(P2->health2, &Health2::EndofGame, this, &Game::slotEndofGame);
}

void Game::sBullet(QPointF start, qreal angle)
{
    Bullet *bullet = new Bullet(start, angle);
    scene->addItem(bullet);
    connect(bullet, &Bullet::hit, P1, &Tank::getHit);
    connect(bullet, &Bullet::hit, P2, &Tank::getHit);
}

void Game::slotEndofGame(int ID)
{

    scene->clear();
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("P" + QString::number(ID) + " is Winner"));

    QFont titleFont("times",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // create the StartAgain button
    Button* playButton = new Button(QString("Restart Game"));
    int PAxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int PAyPos = 275;
    playButton->setPos(PAxPos,PAyPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    // create the Menu button
    Button* Menu = new Button(QString("Menu"));
    int MxPos = this->width()/2 - Menu->boundingRect().width()/2;
    int MyPos = 350;
    Menu->setPos(MxPos,MyPos);
    connect(Menu,SIGNAL(clicked()),this,SLOT(Menu()));
    scene->addItem(Menu);

    // create the quit button
    Button* quitButton = new Button(QString("Exit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 425;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);

}

void Game::Menu()
{
    scene->clear();
    displayMainMenu();
}


