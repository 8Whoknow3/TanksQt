#include "Health.h"

Health::Health(QString _name, int _health, int _ID, QGraphicsItem * parent)
    : QGraphicsTextItem(parent)
{
    health =_health;
    maxHealth = _health;

    // Draw the Health
    setPlainText(QString(_name) + QString(": ") + QString::number(health));
    if(_ID == 2)
        setDefaultTextColor(Qt::blue);
    else if(_ID == 1)
        setDefaultTextColor(Qt::red);
    setFont(QFont("times",25));
}

void Health::Damage(int _health, int _ID)
{
    health -= _health;
    if(_ID == 2){
        setPlainText(QString::number(_ID - 1) + QString(": ") + QString::number(health));
    }
    else if(_ID == 1){
        setPlainText(QString::number(_ID + 1) + QString(": ") + QString::number(health));

    }
    setFont(QFont("times",25));
    if(health == 0){
        emit EndofGame(_ID);
    }
}
