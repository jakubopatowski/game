#pragma once

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include"SFML/Network.hpp"

class Game
{
  public:
    Game();
    virtual ~Game();

    void gameLoop();

    void update();
    void render();

  private:
    void poolEvents();

    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;

    //Game objects
    sf::RectangleShape enemy;
};
