#ifndef HEALTH_H
#define HEALTH_H

#include <QObject>
#include <QGraphicsTextItem>
#include <QFont>

class Health : public QGraphicsTextItem
{
    Q_OBJECT
public:
    explicit Health(QString _name, int _health, int _ID, QGraphicsItem * parent = nullptr);

private:
    int health;
    int maxHealth;
signals:
    void EndofGame(int ID);

public slots:
    void Damage(int _health, int _ID);
};

#endif // HEALTH_H
