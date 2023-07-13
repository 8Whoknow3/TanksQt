#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QObject>
#include <QPainter>
#include <QPainterPath>
#include <QGraphicsItem>

class Bullet : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Bullet(QPointF start, qreal a, QObject *parent = nullptr);

    QRectF boundingRect() const;    // For Draw Bullet
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    qreal Bangle;

signals:
    void hit(QGraphicsItem *item);

public slots:
    void bulletMove();

};

#endif // BULLET_H
