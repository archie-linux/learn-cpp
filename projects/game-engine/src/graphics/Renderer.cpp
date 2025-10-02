#include "graphics/Renderer.h"

void Renderer::render(const std::vector<GameObject*>& objects) {
    window.clear();
    for (auto& obj : objects) {
        obj->draw(window);
    }
    window.display();
}
