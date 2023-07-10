#ifndef MAPCREATOR_H
#define MAPCREATOR_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class MapCreator : public QGraphicsPixmapItem
{
public:
    explicit MapCreator();

    void creataMap(QGraphicsScene *scene, int s, QGraphicsItem * parent = 0);

private:
    int row;
    int col;
    int character;
};

#endif // MAPCREATOR_H
