#ifndef MAPCREATOR_H
#define MAPCREATOR_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class MapCreator : public QGraphicsPixmapItem
{
public:
    explicit MapCreator();

    void creataMap(QGraphicsScene *scene, QString a = "", QGraphicsItem * parent = 0);

private:
    int row;
    int col;
    int character;
};

#endif // MAPCREATOR_H
