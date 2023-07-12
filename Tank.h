#ifndef TANK_H
#define TANK_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QPainterPath>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Health.h"

class Tank : public QObject,  public QGraphicsItem
{
    Q_OBJECT
private:
    QString playerName;
    QString tankType;
    int speed;
    int damage;
    int tank_ID;
    qreal angle;
    int H;


public:
    explicit Tank(QString _name, QString _Type, QObject *parent = 0);
    ~Tank();
    Health *health;

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void hit(int _damage);

    static int numTanks;


signals:

public slots:
    void TankMove1(); // moving by WASD
    void TankMove2(); // moving by -> <-
};

#endif // TANK_H
