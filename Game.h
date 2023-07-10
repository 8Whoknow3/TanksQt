#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "MapCreator.h"
#include "Tank.h"
#include "QTimer"

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    explicit Game(QGraphicsView *parent = nullptr);

    void displayMainMenu();
    QGraphicsScene* scene;
    int M;
    int Tank1;
    int Tank2;
    MapCreator *map;

    Tank *P1;
    Tank *P2;

    QTimer *timer;

signals:

public slots:
    void Smap();
    void newTank();
    // select tanks
    void SMT1();
    void SMT2();
    void SMT3();
    void T1();
    void T2();
    void T3();
    void TT1();
    void TT2();
    void TT3();

    void start();

};

#endif // GAME_H
