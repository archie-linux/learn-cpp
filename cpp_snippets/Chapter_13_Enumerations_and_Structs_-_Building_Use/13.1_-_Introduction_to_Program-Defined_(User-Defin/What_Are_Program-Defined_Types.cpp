// Better approach with user-defined types
enum class GameState 
{
    menu,
    playing,
    paused,
    gameOver
};

struct Player 
{
    std::string name;
    int health;
    int score;
};

GameState currentState = GameState::playing;  // Clear and type-safe!
Player hero { "Link", 100, 0 };
