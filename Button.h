#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsTextItem>
#include <QBrush>

class Button : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
private:
    QGraphicsTextItem* text;

public:
    explicit Button(QString name, QGraphicsItem *parent = nullptr);
    ~Button();

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

signals:
    void clicked();
};

#endif // BUTTON_H
