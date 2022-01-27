#pragma once

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Transformable.hpp"

class IGameObject
{
  public:
    virtual ~IGameObject() {}

    virtual bool interacted( const sf::Vector2f& mousePosView ) = 0;
    virtual void update() = 0;

    virtual const sf::Drawable* getDrawable() = 0;
    virtual const sf::Transformable* getTranformable() = 0; 
};
