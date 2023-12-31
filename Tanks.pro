QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Box.cpp \
    Bullet.cpp \
    Button.cpp \
    Forest.cpp \
    Game.cpp \
    Health1.cpp \
    Health2.cpp \
    MapCreator.cpp \
    Tank.cpp \
    Wall.cpp \
    main.cpp

HEADERS += \
    Box.h \
    Bullet.h \
    Button.h \
    Forest.h \
    Game.h \
    Health1.h \
    Health2.h \
    MapCreator.h \
    Tank.h \
    Wall.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Res.qrc
