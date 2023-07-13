#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QInputDialog>
#include <Button.h>
#include <QBrush>
#include <MapCreator.h>
#include <QTimer>
#include <QDir>
#include "MapCreator.h"
#include "Tank.h"

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    explicit Game(QGraphicsView *parent = nullptr);
    ~Game();

    void displayMainMenu();

    QGraphicsScene* scene;
    int M;      // Map Info
    MapCreator *map;
    QStringList Maps;

    QList <QString > Tanksname;     // Tanks Info
    QStringList TanksType;
    QString Player1;    // Player1 Info
    QString Tank1;
    Tank *P1;

    QString Player2;    // Player2 Info
    QString Tank2;
    Tank *P2;

    QTimer *timer;

signals:

public slots:
    void selector();
    void newTank();
    void start();
    void sBullet(QPointF start, qreal angle);   // Bullet Maker
    void slotEndofGame(int ID);
    void Menu();
};

#endif // GAME_H
