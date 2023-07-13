#ifndef TANK_H
#define TANK_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QPainterPath>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Health1.h"
#include "Health2.h"

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
    Health1 *health1;
    Health2 *health2;

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void hit(int _damage);

    static int numTanks;


signals:
    void SBullet(QPointF start, qreal angle);
    void Damage(int health, int ID);

public slots:
    void TankMove1(); // moving by WASD
    void TankMove2(); // moving by -> <-
    void getHit(QGraphicsItem *item);
};

#endif // TANK_H
