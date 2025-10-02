#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include "core/GameObject.h"
#include <vector>

class Renderer {
public:
    Renderer(sf::RenderWindow& win) : window(win) {}
    void render(const std::vector<GameObject*>& objects);

private:
    sf::RenderWindow& window;
};

#endif
