#include "MapHelper.h"
#include <QGraphicsView>
#include <QGraphicsItem>

MapHelper::MapHelper(int a)
{
    if(a == 1)
        setPixmap(QPixmap(":/IMAGE/Images/bricks.png"));
    else if(a == 2)
        setPixmap(QPixmap(":/IMAGE/Images/box.png"));
    else if(a == 3)
        setPixmap(QPixmap(":/IMAGE/Images/forest.png"));
}
