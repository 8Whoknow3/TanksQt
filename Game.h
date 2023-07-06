#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    explicit Game(QGraphicsView *parent = nullptr);

    void displayMainMenu();
    QGraphicsScene* scene;

signals:

public slots:
    void start();
    void newTank();
    void Map_1();
    void Map_2();
    void Map_3();

};

#endif // GAME_H
