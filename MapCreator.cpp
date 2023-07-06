#include "MapCreator.h"
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QFile>
#include "MapHelper.h"

MapCreator::MapCreator()
{

}

void MapCreator::creataMap(QGraphicsScene *scene, QString a, QGraphicsItem *parent)
{
    QFile file(":/Maps/maps/map_" + a + ".txt");

    row = 0;
    col = 0;

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }

    QTextStream in(&file);
    while(!in.atEnd()){
        row++;
        col = 0;
        QString line = in.readLine();
        for(int i = 0; i < line.size(); i++){
            if(line[i] == '1'){
                MapHelper *a = new MapHelper(1);
                a->setPos(col * 50, row * 50);
                scene->addItem(a);
            }
            else if(line[i] == ' '){
                col++;
            }
            else if(line[i] == '2'){
                MapHelper *a = new MapHelper(2);
                a->setPos(col * 50, row * 50);
                scene->addItem(a);
            }
            else if(line[i] == '3'){
                MapHelper *a = new MapHelper(3);
                a->setPos(col * 50, row * 50);
                scene->addItem(a);
            }
        }

    }
}
