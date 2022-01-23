#pragma once

#include "IGameObject.hpp"
#include "SFML/Graphics.hpp"

class Asteroid : public IGameObject
{
  public:
    Asteroid();
    virtual ~Asteroid() { delete m_obj; };

    virtual bool interacted( const sf::Vector2f& mousePosView );
    virtual void update();
    virtual sf::Drawable* getDrawable() { return m_obj; };

  private:
    sf::RectangleShape* m_obj;
};
