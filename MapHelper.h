#ifndef MAPHELPER_H
#define MAPHELPER_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

class MapHelper : public QGraphicsPixmapItem
{
public:
    MapHelper(int a);
private:
    int id;
};

#endif // MAPHELPER_H
