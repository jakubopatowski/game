#include "game.hpp"
#include "asteroid.hpp"
#include <iostream>

Game::Game() {
    videoMode.height = 600;
    videoMode.width = 800;

    window =
        new sf::RenderWindow( videoMode, "My first game", sf::Style::Titlebar | sf::Style::Close );
    window->setFramerateLimit( 60 );

    background_texture.loadFromFile( "background.png" );
    background_sprite.setTexture( background_texture );
    background_sprite.setScale( sf::Vector2f( 2.0, 2.0 ) );

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
        bool toDelete = false;

        // check if clicked
        if ( sf::Mouse::isButtonPressed( sf::Mouse::Left ) ) {
            if ( ( *it )->interacted( mousePosView ) ) {
                toDelete = true;
            }
        }

        // check if out of screen
        if ( ( *it )->getTranformable()->getPosition().y > window->getSize().y ) {
            toDelete = true;
        }

        if ( toDelete ) {
            it = enemies.erase( it );
            continue;
        }

        ( *it )->update();
        ++it;
    }

    // std::cout << "Mouse position: " << sf::Mouse::getPosition( *window ).x << " "
    //          << sf::Mouse::getPosition( *window ).y << '\n';
}

void Game::render() {
    window->clear();
    window->draw( background_sprite );
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
