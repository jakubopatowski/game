#pragma once

#include "SFML/Graphics.hpp"
#include "game_object.hpp"

class Asteroid : public GameObject
{
  public:
    Asteroid();
    virtual ~Asteroid() { delete m_obj; };

    virtual void update();
    virtual sf::Drawable* getDrawable() { return m_obj; };

  private:
    sf::RectangleShape* m_obj;
};
