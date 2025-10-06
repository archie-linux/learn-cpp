#include <iostream>
#include <string>

class Player {
private:
    std::string m_name;
    int m_health;
    int m_level;
    double m_experience;

public:
    // Default constructor
    Player() {
        m_name = "Unknown";
        m_health = 100;
        m_level = 1;
        m_experience = 0.0;
        std::cout << "Default player created\n";
    }
    
    // Parameterized constructor
    Player(const std::string& name, int health = 100) {
        m_name = name;
        m_health = health;
        m_level = 1;
        m_experience = 0.0;
        std::cout << "Player " << m_name << " created\n";
    }
    
    // Another parameterized constructor
    Player(const std::string& name, int health, int level, double exp) {
        m_name = name;
        m_health = health;
        m_level = level;
        m_experience = exp;
        std::cout << "Experienced player " << m_name << " created\n";
    }
    
    void displayStats() const {
        std::cout << "Player: " << m_name << " (Level " << m_level 
                  << ", Health: " << m_health << ", XP: " << m_experience << ")\n";
    }
};

int main() {
    Player newbie;                              // Default constructor
    Player hero{"Link", 120};                   // Parameterized constructor  
    Player veteran{"Zelda", 150, 10, 9999.0};  // Full parameterized constructor
    
    newbie.displayStats();
    hero.displayStats();
    veteran.displayStats();
    
    return 0;
}
