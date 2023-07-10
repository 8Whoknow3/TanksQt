#include "MapHelper.h"
#include <QGraphicsView>
#include <QGraphicsItem>

MapHelper::MapHelper(int a)
{
    if(a == 1){
        setPixmap(QPixmap(":/IMAGE/Images/bricks.png"));
        id = 1;
    }
    else if(a == 2){
        setPixmap(QPixmap(":/IMAGE/Images/box.png"));
        id = 2;
    }
    else if(a == 3){
        setPixmap(QPixmap(":/IMAGE/Images/forest.png"));
        id = 3;
    }
}
