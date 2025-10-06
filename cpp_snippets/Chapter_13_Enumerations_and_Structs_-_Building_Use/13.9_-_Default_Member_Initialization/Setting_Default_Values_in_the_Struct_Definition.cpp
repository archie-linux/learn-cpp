#include <iostream>
#include <string>

struct GameCharacter 
{
    std::string name = "Unknown";    // Default value
    int health = 100;               // Default value
    int mana = 50;                  // Default value
    int level = 1;                  // Default value
    bool isAlive = true;            // Default value
};

int main() 
{
    // Use defaults
    GameCharacter npc{};
    std::cout << "NPC: " << npc.name << ", Health: " << npc.health << '\n';
    
    // Override some defaults
    GameCharacter hero{"Link", 120, 75, 5};  // name, health, mana, level
    std::cout << "Hero: " << hero.name << ", Level: " << hero.level << '\n';
    
    // Override specific members (C++20 designated initializers)
    GameCharacter boss{
        .name = "Ganondorf",
        .health = 500,
        .level = 50
        // mana, isAlive use defaults
    };
    
    std::cout << "Boss: " << boss.name << ", Health: " << boss.health 
              << ", Mana: " << boss.mana << '\n';
    
    return 0;
}
