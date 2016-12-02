#include "app.h"
#include "iostream"
#include "utils/score.h"
#include "graphics/splashscreen.h"

App::App()
    :m_window{sf::VideoMode{SCREEN_WIDTH, SCREEN_HEIGHT, 32},"Runner",sf::Style::Close}
{
    m_window.setFramerateLimit(60);
}

void App::run()
{

    Splashscreen sc{sf::Vector2f{SCREEN_WIDTH, SCREEN_HEIGHT}};

    while(sc.draw(&m_window)){}

    Menu* menu = new Menu{&m_window};

    while(menu->update())
    {
        menu->draw();

        if(menu->playBtn()->isClicked()){
            Model model{(int) m_window.getSize().x, (int) m_window.getSize().y};
            GameView view{&m_window, &model};
            while(view.treatEvents()){
                model.nextStep();
                view.synchronize();
                view.draw();
            }
            addScore(model.getPlayerScore());
            delete menu;
            menu = new Menu{&m_window};
        }

        if(menu->exitBtn()->isClicked()){
            m_window.close();
        }
    }

    delete menu;
}


