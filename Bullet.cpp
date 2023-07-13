#include "Bullet.h"
#include <QTimer>
#include "Box.h"
#include "Forest.h"
#include "Wall.h"
#include "Tank.h"

Bullet::Bullet(QPointF start, qreal a, QObject *parent)
    : QObject{parent}, QGraphicsItem()
{
    setRotation(0);
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(bulletMove()));
    Bangle = 180 + a;
    timer->start(30);

    // Setting the rotation angle of the graphic object
    setRotation(Bangle);
    setPos(start);
}

QRectF Bullet::boundingRect() const
{
    return QRectF(0,0,2,4);
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(Qt::black);
    painter->drawRect(0,0,2,4);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}
void Bullet::bulletMove()
{
    setPos(mapToParent(0, -10));

    // check for items that bullet hit
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for(int i = 0, n = colliding_items.size(); i < n; i++){
        if (typeid(*(colliding_items[i])) == typeid(Box)){
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            delete colliding_items[i];
            delete this;

            return;
        }
        if (typeid(*(colliding_items[i])) == typeid(Wall)){
            scene()->removeItem(this);
            delete this;

            return;
        }
        if (typeid(*(colliding_items[i])) == typeid(Tank)){
            // Delete Bullet
            scene()->removeItem(this);
            emit hit(colliding_items[i]);

            delete this;

            return;
        }
    }

    // For Out of border
    if(x() < 0){
        deleteLater();
    }
    if(x() > 1485){
        deleteLater();
    }

    if(y() < 0){
        deleteLater();
    }
    if(y() > 770){
        deleteLater();
    }

}
