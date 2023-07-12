#ifndef HEALTH1_H
#define HEALTH1_H

#include <QObject>
#include <QGraphicsTextItem>
#include <QFont>

class Health1 : public QGraphicsTextItem
{
    Q_OBJECT
public:
    explicit Health1(QString _name, int _health, QGraphicsItem * parent = nullptr);

private:
    int health;
    int maxHealth;
    QString name;

signals:
    void EndofGame(int ID);

public slots:
    void Damage(int _health, int _ID);
};

#endif // HEALTH1_H
