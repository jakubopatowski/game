#pragma once

#include "IGameObject.hpp"
#include "SFML/Graphics.hpp"

#include<functional>

class Asteroid : public IGameObject
{
  public:
    Asteroid();
    virtual ~Asteroid() { delete m_obj; };

    virtual bool interacted( const sf::Vector2f& mousePosView );
    virtual void update();
    virtual const sf::Drawable* getDrawable() { return m_obj; };
    virtual const sf::Transformable* getTranformable() { return m_obj; }

  private:
    sf::RectangleShape* m_obj;
    std::function< float( float ) > motion;
};
