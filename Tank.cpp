#include "Tank.h"
#include "windows.h"
#include <QFile>

int Tank::numTanks = 0;

Tank::Tank(QString _name, QString _Type, QObject *parent)
    : QObject{parent}
{
    playerName = _name;
    tankType = _Type;

    angle = 0;     //   Setting the rotation angle of the graphic object
    setRotation(angle);  // Set the angle of rotation of the graphic object
    tank_ID = ++numTanks;

    QFile file(":/Info/Tanks/" + _Type + ".txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    QString line = in.readLine();
    bool ok;
    speed = line.toInt(&ok);
    line = in.readLine();
    damage = line.toInt(&ok);
    line = in.readLine();
    H = line.toInt(&ok);

    if(tank_ID == 1){
        health1 = new Health1(playerName, H);
        health2 = NULL;
        connect(this, &Tank::Damage, health1, &Health1::Damage1);
    }
    else if(tank_ID == 2){
        health2 = new Health2(playerName, H);
        health1 = NULL;
        connect(this, &Tank::Damage, health2, &Health2::Damage2);
    }
}

Tank::~Tank()
{

}

QRectF Tank::boundingRect() const
{
    // limit the area tanks can lies
    return QRectF(-20, -25, 45, 50);
}

QPainterPath Tank::shape() const
{
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}

void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (tank_ID == 1)
        painter->setBrush(Qt::blue);
    else if (tank_ID == 2)
        painter->setBrush(Qt::red);

    // body
    painter->drawRect(-15,-25,30,40);
    painter->setBrush(Qt::black);
    // left wheel
    painter->drawRect(-20,-20,5,30);
    // right wheel
    painter->drawRect(15,-20,5,30);
    // canon
    painter->drawRect(-5,-5,10,30);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Tank::TankMove1()
{
    if(GetAsyncKeyState(VK_LEFT)){
        // Set the rotation 10 degrees to the left
        angle -= 10;
        // Rotating the object
        setRotation(angle);

        // see if we tach wall or not
        if(!(this->scene()->collidingItems(this).isEmpty())){
            // Set the rotation 10 degrees to the right
            angle += 10;
            // Rotating the object
            setRotation(angle);
        }
    }
    if(GetAsyncKeyState(VK_RIGHT)){
        angle += 10;
        setRotation(angle);

        if(!scene()->collidingItems(this).isEmpty()){
            angle -= 10;
            setRotation(angle);
        }
    }
    if(GetAsyncKeyState(VK_UP)){
        setPos(mapToParent(0, 5));

        //Move the object 5 pixels forward
        //by translating them into the coordinate system graphic scene
        if(!scene()->collidingItems(this).isEmpty()){
            setPos(mapToParent(0, -5));
        }
    }
    if(GetAsyncKeyState(VK_DOWN)){
        setPos(mapToParent(0, -5));

        if(!scene()->collidingItems(this).isEmpty()){
            setPos(mapToParent(0, 5));
        }
    }
    if(GetAsyncKeyState('K')){
        emit SBullet(mapToScene(0, 25), angle);
    }
}

void Tank::TankMove2()
{
    if(GetAsyncKeyState('A')){
        angle -= 10;
        setRotation(angle);

        if(!(this->scene()->collidingItems(this).isEmpty())){
            angle += 10;
            setRotation(angle);
        }
    }
    if(GetAsyncKeyState('D')){
        angle += 10;
        setRotation(angle);

        if(!scene()->collidingItems(this).isEmpty()){
            angle -= 10;
            setRotation(angle);
        }
    }
    if(GetAsyncKeyState('W')){
        setPos(mapToParent(0, 5));

        if(!scene()->collidingItems(this).isEmpty()){
            setPos(mapToParent(0, -5));
        }
    }
    if(GetAsyncKeyState('S')){
        setPos(mapToParent(0, -5));

        if(!scene()->collidingItems(this).isEmpty()){
            setPos(mapToParent(0, 5));
        }
    }
    if(GetAsyncKeyState('C'))
        emit SBullet(mapToScene(0, 25), angle);
}

void Tank::getHit(QGraphicsItem *item)
{
    if (item != this){
        if(tank_ID == 1)
            emit Damage(damage, 2);
        if(tank_ID == 2)
            emit Damage(damage, 1);
    }
}
