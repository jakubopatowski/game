#pragma once

#include "SFML/Graphics/Drawable.hpp"

class IGameObject
{
  public:
    virtual ~IGameObject() {}

    virtual bool interacted( const sf::Vector2f& mousePosView ) = 0;
    virtual void update() = 0;
    virtual sf::Drawable* getDrawable() = 0;
};
