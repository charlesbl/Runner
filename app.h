#ifndef APP_H
#define APP_H

#include "view/gameview.h"
#include "model/model.h"
#include "menu/menu.h"

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;

class App{
private:
    sf::RenderWindow m_window;

public:
    App();
    void run();

};

#endif // APP_H
