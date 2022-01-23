#pragma once

#include"SFML/Audio.hpp"
#include"SFML/Graphics.hpp"
#include"SFML/System.hpp"
#include"SFML/Window.hpp"
#include"SFML/Network.hpp"
#include<vector>

class IGameObject;
class Asteroid;
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
    
    void updateMousePositions();

    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;

    //Game objects
    void spawnEnemies();
    int spawnCount;
    int spawnOffset;
    std::vector< IGameObject* > enemies;

    //Mouse position
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;
};
