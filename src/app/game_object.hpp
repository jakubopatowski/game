#pragma once

#include "SFML/Graphics/Drawable.hpp"

class GameObject
{
  public:
    virtual ~GameObject() {}
    
    virtual void update() = 0;
    virtual sf::Drawable* getDrawable() = 0;
};
