#include <iostream>
#include <string>
#include <cmath>
#include <random>

class MathUtils {
public:
    // Static utility functions - no instance required
    static double degreesToRadians(double degrees) {
        return degrees * M_PI / 180.0;
    }
    
    static double radiansToDegrees(double radians) {
        return radians * 180.0 / M_PI;
    }
    
    static bool isPrime(int number) {
        if (number <= 1) return false;
        if (number <= 3) return true;
        if (number % 2 == 0 || number % 3 == 0) return false;
        
        for (int i = 5; i * i <= number; i += 6) {
            if (number % i == 0 || number % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
    
    static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    static double distance(double x1, double y1, double x2, double y2) {
        double dx = x2 - x1;
        double dy = y2 - y1;
        return std::sqrt(dx * dx + dy * dy);
    }
};

class Color {
private:
    int m_red, m_green, m_blue;
    
    // Private constructor - force use of factory methods
    Color(int red, int green, int blue) 
        : m_red{clamp(red)}, m_green{clamp(green)}, m_blue{clamp(blue)} {}

public:
    // Static factory methods
    static Color fromRGB(int red, int green, int blue) {
        return Color{red, green, blue};
    }
    
    static Color fromHex(const std::string& hexColor) {
        // Simplified hex parsing (assumes #RRGGBB format)
        if (hexColor.length() == 7 && hexColor[0] == '#') {
            int red = std::stoi(hexColor.substr(1, 2), nullptr, 16);
            int green = std::stoi(hexColor.substr(3, 2), nullptr, 16);
            int blue = std::stoi(hexColor.substr(5, 2), nullptr, 16);
            return Color{red, green, blue};
        }
        return Color{0, 0, 0}; // Default to black for invalid input
    }
    
    static Color random() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<> dis(0, 255);
        
        return Color{dis(gen), dis(gen), dis(gen)};
    }
    
    // Predefined color constants (static factory methods)
    static Color red() { return Color{255, 0, 0}; }
    static Color green() { return Color{0, 255, 0}; }
    static Color blue() { return Color{0, 0, 255}; }
    static Color white() { return Color{255, 255, 255}; }
    static Color black() { return Color{0, 0, 0}; }
    
    // Instance methods
    int getRed() const { return m_red; }
    int getGreen() const { return m_green; }
    int getBlue() const { return m_blue; }
    
    void display() const {
        std::cout << "RGB(" << m_red << ", " << m_green << ", " << m_blue << ")";
    }
    
    std::string toHex() const {
        char buffer[8];
        std::sprintf(buffer, "#%02X%02X%02X", m_red, m_green, m_blue);
        return std::string(buffer);
    }
    
private:
    static int clamp(int value) {
        return (value < 0) ? 0 : (value > 255) ? 255 : value;
    }
};

// Singleton pattern using static members
class Logger {
private:
    static Logger* s_instance;
    std::string m_logLevel;
    bool m_enabled;
    
    // Private constructor prevents direct instantiation
    Logger() : m_logLevel{"INFO"}, m_enabled{true} {}

public:
    // Static method to get singleton instance
    static Logger& getInstance() {
        if (s_instance == nullptr) {
            s_instance = new Logger();
        }
        return *s_instance;
    }
    
    // Delete copy constructor and assignment operator
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    
    static void setLogLevel(const std::string& level) {
        getInstance().m_logLevel = level;
    }
    
    static void enable() { getInstance().m_enabled = true; }
    static void disable() { getInstance().m_enabled = false; }
    
    static void log(const std::string& message) {
        Logger& logger = getInstance();
        if (logger.m_enabled) {
            std::cout << "[" << logger.m_logLevel << "] " << message << '\n';
        }
    }
    
    static void info(const std::string& message) {
        log("INFO: " + message);
    }
    
    static void error(const std::string& message) {
        log("ERROR: " + message);
    }
    
    // Cleanup (optional - for demonstration)
    static void cleanup() {
        delete s_instance;
        s_instance = nullptr;
    }
};

// Static member definition
Logger* Logger::s_instance = nullptr;

int main() {
    // Using static utility functions
    std::cout << "45 degrees = " << MathUtils::degreesToRadians(45.0) << " radians\n";
    std::cout << "Is 17 prime? " << (MathUtils::isPrime(17) ? "Yes" : "No") << '\n';
    std::cout << "GCD(48, 18) = " << MathUtils::gcd(48, 18) << '\n';
    std::cout << "Distance: " << MathUtils::distance(0, 0, 3, 4) << '\n';
    
    // Using static factory methods
    Color red = Color::red();
    Color fromHex = Color::fromHex("#FF5733");
    Color random = Color::random();
    
    std::cout << "\nColors:\n";
    std::cout << "Red: "; red.display(); std::cout << " -> " << red.toHex() << '\n';
    std::cout << "From hex: "; fromHex.display(); std::cout << " -> " << fromHex.toHex() << '\n';
    std::cout << "Random: "; random.display(); std::cout << " -> " << random.toHex() << '\n';
    
    // Using singleton logger
    Logger::info("Application started");
    Logger::setLogLevel("DEBUG");
    Logger::log("This is a debug message");
    Logger::error("This is an error message");
    
    Logger::disable();
    Logger::info("This won't be printed");
    
    Logger::enable();
    Logger::info("Logging re-enabled");
    
    Logger::cleanup();  // Optional cleanup
    
    return 0;
}
