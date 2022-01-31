#include "asteroid.hpp"
#include<random>
#include<chrono>
#include<cmath>

Asteroid::Asteroid() {

    m_obj = new sf::RectangleShape();

    unsigned int seed;
    std::default_random_engine dre;
    dre.seed( std::chrono::system_clock::now().time_since_epoch().count() );
    std::uniform_int_distribution< int > di( 20, 780 );

    float tmp = di( dre );
    m_obj->setPosition( tmp, -10.f );
    m_obj->setSize( sf::Vector2f( 100.f, 100.f ) );
    m_obj->setScale( sf::Vector2f( 0.5f, 0.5f ) );
    m_obj->setFillColor( sf::Color::Cyan );
    m_obj->setOutlineColor( sf::Color::Green );
    m_obj->setOutlineThickness( 1.f );

    motion = []( float x ) {
        float y = x * 0.01 + 100;
        y = 300 * sin( y ) + 300;
        return y;
    };
}

bool Asteroid::interacted( const sf::Vector2f& mousePosView ) {
    if(m_obj->getGlobalBounds().contains( mousePosView )){
        return true; 
    }
    return false;
}

void Asteroid::update() {
    auto pos = m_obj->getPosition();
    auto x = motion( pos.y + 1.f );
    m_obj->setPosition( x, pos.y + 1.f );
}