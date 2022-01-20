#include "game.hpp"
#include <iostream>

Game::Game() {
    videoMode.height = 600;
    videoMode.width = 800;
    window =
        new sf::RenderWindow( videoMode, "My first game", sf::Style::Titlebar | sf::Style::Close );
    window->setFramerateLimit( 60 );

    enemy.setPosition( sf::Vector2f( 100.f, 100.f ) );
    enemy.setSize( sf::Vector2f( 100.f, 100.f ) );
    enemy.setFillColor( sf::Color::Cyan );
    enemy.setOutlineColor( sf::Color::Green );
    enemy.setOutlineThickness( 1.f );
}

Game::~Game() { delete window; }

void Game::gameLoop() {
    while ( window->isOpen() ) {
        update();
        render();
    }
}

void Game::update() {
    poolEvents();
    std::cout << "Mouse position: " << sf::Mouse::getPosition( *window ).x << " "
              << sf::Mouse::getPosition( *window ).y << '\n';
}

// putting pixels on the screen
void Game::render() {
    window->clear();

    window->draw( enemy );

    window->display();
}

void Game::poolEvents() {
    while ( window->pollEvent( ev ) ) {
        switch ( ev.type ) {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::KeyPressed:
            if ( ev.key.code == sf::Keyboard::Escape )
                window->close();
            break;
        }
    }
}
