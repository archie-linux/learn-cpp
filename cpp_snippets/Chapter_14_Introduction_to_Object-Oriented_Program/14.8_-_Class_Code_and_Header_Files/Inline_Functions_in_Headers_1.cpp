#include "Timer.h"

double Timer::getElapsedSeconds() const {
    if (!m_running) {
        return 0.0;
    }
    
    auto currentTime = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(
        currentTime - m_startTime);
    
    return elapsed.count() / 1000.0;
}
