#include "MapCreator.h"
#include "Wall.h"
#include "Box.h"
#include "Forest.h"

MapCreator::MapCreator(QGraphicsScene *scene, int s, QGraphicsItem *parent):
    QGraphicsPixmapItem(parent)
{
    QString a = QString::number(s);
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
                Wall *a = new Wall();
                a->setPos(col * 50, row * 50);
                scene->addItem(a);
            }
            else if(line[i] == ' '){
                col++;
            }
            else if(line[i] == '2'){
                Box *a = new Box();
                a->setPos(col * 50, row * 50);
                scene->addItem(a);
            }
            else if(line[i] == '3'){
                Forest *a = new Forest();
                a->setPos(col * 50, row * 50);
                scene->addItem(a);
            }
        }
    }
    file.close();
}
