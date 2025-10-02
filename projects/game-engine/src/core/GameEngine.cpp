#include "core/GameEngine.h"

GameEngine::GameEngine() : window(sf::VideoMode(800, 600), "Simple Game Engine"), renderer(window) {
    // Initialize objects
    Player* player = new Player(sf::Vector2f(50, 250));
    GameObject* ball = new GameObject("assets/ball.png", sf::Vector2f(400, 300));
    ball->setVelocity(sf::Vector2f(200.f, 100.f));  // Initial velocity for physics
    Enemy* enemy = new Enemy(sf::Vector2f(700, 250), ball);

    objects.push_back(player);
    objects.push_back(ball);
    objects.push_back(enemy);
}

void GameEngine::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        float deltaTime = clock.restart().asSeconds();

        // Update objects and physics
        for (auto& obj : objects) obj->update(deltaTime);
        Physics::update(objects, deltaTime);

        // Render
        renderer.render(objects);
    }
}
