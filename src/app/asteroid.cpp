#include "asteroid.hpp"
#include<random>
#include<chrono>

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
}

void Asteroid::update() { m_obj->move( sf::Vector2f( 0.f, 1.f ) ); }