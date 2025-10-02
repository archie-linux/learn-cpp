// Timer.h
#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <iostream>

class Timer {
private:
    std::chrono::steady_clock::time_point m_startTime;
    bool m_running;

public:
    Timer() : m_running{false} {}
    
    // Simple functions can be defined inline in header
    void start() {
        m_startTime = std::chrono::steady_clock::now();
        m_running = true;
    }
    
    void stop() {
        m_running = false;
    }
    
    bool isRunning() const { return m_running; }
    
    // More complex function - declare here, define in .cpp
    double getElapsedSeconds() const;
    void displayElapsed() const;
};

// Inline function definition (alternative to defining in class body)
inline void Timer::displayElapsed() const {
    std::cout << "Elapsed time: " << getElapsedSeconds() << " seconds\n";
}

#endif
