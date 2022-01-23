#include "game.hpp"
#include "asteroid.hpp"
#include <iostream>

Game::Game() {
    videoMode.height = 600;
    videoMode.width = 800;

    window =
        new sf::RenderWindow( videoMode, "My first game", sf::Style::Titlebar | sf::Style::Close );
    window->setFramerateLimit( 60 );

    spawnCount = 0;
    spawnOffset = 60;
}

Game::~Game() {
    delete window;
    for ( auto it : enemies ) {
        delete it;
    }
    enemies.clear();
}

void Game::gameLoop() {
    while ( window->isOpen() ) {
        update();
        render();
    }
}

void Game::updateMousePositions() {
    mousePosWindow = sf::Mouse::getPosition( *window );
    mousePosView = window->mapPixelToCoords( mousePosWindow );
}

void Game::update() {
    poolEvents();
    updateMousePositions();

    spawnEnemies();
    for ( auto it = enemies.begin(); it != enemies.end(); ) {
        ( *it )->update();

        // check if clicked
        if ( ( *it )->interacted( mousePosView ) ) {
            it = enemies.erase( it );
        }
        else{
            ++it;
        }
    }

    // std::cout << "Mouse position: " << sf::Mouse::getPosition( *window ).x << " "
    //          << sf::Mouse::getPosition( *window ).y << '\n';
}

void Game::render() {
    window->clear();
    for ( auto obj : enemies ) {
        window->draw( *( obj->getDrawable() ) );
    }
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

void Game::spawnEnemies() {
    if ( spawnCount >= spawnOffset ) {
        auto* enemy = new Asteroid();
        enemies.push_back( enemy );
        spawnCount = 0;
    }
    else {
        ++spawnCount;
    }
}
