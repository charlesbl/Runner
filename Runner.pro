TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra
LIBS += -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-system

SOURCES += main.cpp \
    graphics/animatedgraphicelement.cpp \
    graphics/graphicelement.cpp \
    menu/button.cpp \
    menu/menu.cpp \
    model/model.cpp \
    model/movableelement.cpp \
    model/player.cpp \
    app.cpp \
    graphics/slidingbackground.cpp \
    graphics/animation.cpp \
    view/playerview.cpp \
    view/movablesview.cpp \
    view/gameview.cpp \
    view/view.cpp \
    model/coin.cpp \
    model/healer.cpp \
    model/gameelement.cpp \
    model/car.cpp \
    model/stand.cpp \
    model/trafficlight.cpp \
    model/shield.cpp \
    model/wings.cpp \
    utils/score.cpp \
    graphics/splashscreen.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    graphics/animatedgraphicelement.h \
    graphics/graphicelement.h \
    menu/button.h \
    menu/menu.h \
    model/model.h \
    model/movableelement.h \
    model/player.h \
    app.h \
    graphics/slidingbackground.h \
    graphics/animation.h \
    view/playerview.h \
    view/movablesview.h \
    view/gameview.h \
    view/view.h \
    model/coin.h \
    model/healer.h \
    model/gameelement.h \
    model/car.h \
    utils/clock.h \
    model/stand.h \
    model/trafficlight.h \
    model/shield.h \
    model/wings.h \
    utils/score.h \
    graphics/splashscreen.h

