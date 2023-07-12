#include "Health1.h"

Health1::Health1(QString _name, int _health, QGraphicsItem * parent)
    : QGraphicsTextItem(parent)
{
    health =_health;
    maxHealth = _health;
    name = _name;

    // Draw the Health
    setPlainText(QString(name) + QString(": ") + QString::number(health) + QString("/") + QString::number(maxHealth));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",25));
}

void Health1::Damage(int _health, int _ID)
{
    health -= _health;
    setPlainText(QString(name) + QString(": ") + QString::number(health) + QString("/") + QString::number(maxHealth));
    setFont(QFont("times",25));
    if(health == 0){
        emit EndofGame(_ID);
    }
}
