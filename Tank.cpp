#include "Tank.h"
#include "windows.h"

int Tank::numTanks = 0;

Tank::Tank(int P, int T, QObject *parent)
    : QObject{parent}
{
    angle = 0;     //   Setting the rotation angle of the graphic object
    setRotation(angle);  // Set the angle of rotation of the graphic object
    tank_ID = ++numTanks;
    if(T == 1){
        speed = 6;
        damage = 10;
        H = 80;
    }
    else if(T == 2){
        speed = 5;
        damage = 15;
        H = 100;
    }
    else if(T == 3){
        speed = 4;
        damage = 20;
        H = 120;
    }
    //health = new Health(H, , P);
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
}
