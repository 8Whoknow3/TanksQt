#ifndef HEALTH2_H
#define HEALTH2_H

#include <QObject>
#include <QGraphicsTextItem>
#include <QFont>

class Health2 : public QGraphicsTextItem
{
    Q_OBJECT
public:
    explicit Health2(QString _name, int _health, QGraphicsItem * parent = nullptr);

private:
    int health;
    int maxHealth;
    QString name;

signals:
    void EndofGame(int ID);

public slots:
    void Damage2(int _health, int _ID);
};

#endif // HEALTH2_H
