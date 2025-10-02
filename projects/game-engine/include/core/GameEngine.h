#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <SFML/Graphics.hpp>
#include "graphics/Renderer.h"
#include "physics/Physics.h"
#include <vector>
#include "entities/Player.h"
#include "entities/Enemy.h"

class GameEngine {
public:
    GameEngine();
    void run();

private:
    sf::RenderWindow window;
    Renderer renderer;
    std::vector<GameObject*> objects;  // Efficient data structure for scene management
    sf::Clock clock;
};

#endif
