#include "Health2.h"

Health2::Health2(QString _name, int _health, QGraphicsItem * parent)
    : QGraphicsTextItem(parent)
{
    health =_health;
    maxHealth = _health;
    name = _name;

    // Draw the Health
    setPlainText(QString(name) + QString(": ") + QString::number(health) + QString("/") + QString::number(maxHealth));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",25));
}

void Health2::Damage2(int _health, int _ID)
{
    health -= _health;
    setPlainText(QString(name) + QString("ali ") + QString::number(health) + QString("/") + QString::number(maxHealth));
    setFont(QFont("times",25));
    if(health <= 0){
        emit EndofGame(_ID);
    }
}
