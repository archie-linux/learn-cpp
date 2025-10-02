#include <iostream>
#include <vector>
#include <algorithm>

class GameEntity {
private:
    static int s_nextId;
    static std::vector<GameEntity*> s_allEntities;  // Track all instances
    static bool s_debugMode;
    static int s_maxEntities;
    
    int m_id;
    std::string m_name;
    double m_x, m_y;
    bool m_active;
    
public:
    GameEntity(const std::string& name, double x = 0.0, double y = 0.0)
        : m_id{s_nextId++}, m_name{name}, m_x{x}, m_y{y}, m_active{true} {
        
        if (s_allEntities.size() >= static_cast<size_t>(s_maxEntities)) {
            throw std::runtime_error("Maximum number of entities exceeded");
        }
        
        s_allEntities.push_back(this);
        
        if (s_debugMode) {
            std::cout << "Entity created: " << m_name << " (ID: " << m_id << ")\n";
        }
    }
    
    ~GameEntity() {
        // Remove from static tracking vector
        auto it = std::find(s_allEntities.begin(), s_allEntities.end(), this);
        if (it != s_allEntities.end()) {
            s_allEntities.erase(it);
        }
        
        if (s_debugMode) {
            std::cout << "Entity destroyed: " << m_name << " (ID: " << m_id << ")\n";
        }
    }
    
    // Static configuration functions
    static void setDebugMode(bool enabled) { s_debugMode = enabled; }
    static bool isDebugMode() { return s_debugMode; }
    static void setMaxEntities(int max) { s_maxEntities = max; }
    static int getMaxEntities() { return s_maxEntities; }
    
    // Static entity management
    static size_t getEntityCount() { return s_allEntities.size(); }
    
    static void printAllEntities() {
        std::cout << "=== All Entities (" << s_allEntities.size() << ") ===\n";
        for (const GameEntity* entity : s_allEntities) {
            entity->printInfo();
        }
    }
    
    static GameEntity* findEntityById(int id) {
        for (GameEntity* entity : s_allEntities) {
            if (entity->m_id == id) {
                return entity;
            }
        }
        return nullptr;
    }
    
    static void updateAllEntities() {
        for (GameEntity* entity : s_allEntities) {
            if (entity->m_active) {
                entity->update();
            }
        }
    }
    
    // Instance methods
    int getId() const { return m_id; }
    const std::string& getName() const { return m_name; }
    void setPosition(double x, double y) { m_x = x; m_y = y; }
    void setActive(bool active) { m_active = active; }
    bool isActive() const { return m_active; }
    
    void printInfo() const {
        std::cout << "  " << m_name << " (ID: " << m_id << ") at (" 
                  << m_x << ", " << m_y << ") " 
                  << (m_active ? "[Active]" : "[Inactive]") << '\n';
    }
    
private:
    void update() {
        // Simple movement simulation
        m_x += 1.0;
        if (s_debugMode) {
            std::cout << m_name << " moved to (" << m_x << ", " << m_y << ")\n";
        }
    }
};

// Static member definitions
int GameEntity::s_nextId = 1;
std::vector<GameEntity*> GameEntity::s_allEntities;
bool GameEntity::s_debugMode = false;
int GameEntity::s_maxEntities = 100;

int main() {
    // Configure system
    GameEntity::setDebugMode(true);
    GameEntity::setMaxEntities(5);
    
    std::cout << "Max entities: " << GameEntity::getMaxEntities() << '\n';
    std::cout << "Current count: " << GameEntity::getEntityCount() << '\n';
    
    // Create entities
    GameEntity player{"Player", 0.0, 0.0};
    GameEntity enemy1{"Enemy1", 10.0, 5.0};
    GameEntity enemy2{"Enemy2", -5.0, 8.0};
    
    GameEntity::printAllEntities();
    
    // Find specific entity
    GameEntity* found = GameEntity::findEntityById(2);
    if (found) {
        std::cout << "Found entity: " << found->getName() << '\n';
        found->setActive(false);
    }
    
    // Update all entities
    std::cout << "\n=== Updating all entities ===\n";
    GameEntity::updateAllEntities();
    
    GameEntity::printAllEntities();
    
    return 0;
    // All entities destroyed automatically, removed from static vector
}
