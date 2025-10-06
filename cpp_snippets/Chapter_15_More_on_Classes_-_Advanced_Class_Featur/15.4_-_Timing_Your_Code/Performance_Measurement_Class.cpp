#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <string>

class Timer {
private:
    std::chrono::steady_clock::time_point m_startTime;
    std::chrono::steady_clock::time_point m_endTime;
    bool m_running;

public:
    Timer() : m_running{false} {}
    
    void start() {
        m_startTime = std::chrono::steady_clock::now();
        m_running = true;
    }
    
    void stop() {
        if (m_running) {
            m_endTime = std::chrono::steady_clock::now();
            m_running = false;
        }
    }
    
    double getElapsedMilliseconds() const {
        if (m_running) {
            auto currentTime = std::chrono::steady_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(
                currentTime - m_startTime);
            return elapsed.count() / 1000.0;
        } else {
            auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(
                m_endTime - m_startTime);
            return elapsed.count() / 1000.0;
        }
    }
    
    double getElapsedSeconds() const {
        return getElapsedMilliseconds() / 1000.0;
    }
    
    bool isRunning() const { return m_running; }
};

// RAII Timer for automatic measurement
class ScopedTimer {
private:
    Timer m_timer;
    std::string m_label;

public:
    ScopedTimer(const std::string& label) : m_label{label} {
        std::cout << "Starting: " << m_label << '\n';
        m_timer.start();
    }
    
    ~ScopedTimer() {
        m_timer.stop();
        std::cout << "Completed: " << m_label 
                  << " (" << m_timer.getElapsedMilliseconds() << " ms)\n";
    }
};

// Performance testing functions
void slowFunction() {
    std::vector<int> data(1000000);
    for (int i = 0; i < 1000000; ++i) {
        data[i] = i * i;
    }
    std::sort(data.begin(), data.end());
}

void fastFunction() {
    std::vector<int> data;
    data.reserve(1000000);  // Pre-allocate memory
    for (int i = 0; i < 1000000; ++i) {
        data.push_back(i * i);
    }
}

int main() {
    // Manual timing
    Timer manualTimer;
    
    manualTimer.start();
    slowFunction();
    manualTimer.stop();
    
    std::cout << "Manual timing - Slow function: " 
              << manualTimer.getElapsedMilliseconds() << " ms\n";
    
    // RAII automatic timing
    {
        ScopedTimer autoTimer{"Fast function execution"};
        fastFunction();
        // Timer automatically stops and reports when going out of scope
    }
    
    // Multiple measurements
    std::vector<double> measurements;
    for (int i = 0; i < 5; ++i) {
        Timer timer;
        timer.start();
        fastFunction();
        timer.stop();
        measurements.push_back(timer.getElapsedMilliseconds());
    }
    
    double average = 0.0;
    for (double time : measurements) {
        average += time;
    }
    average /= measurements.size();
    
    std::cout << "Average time over 5 runs: " << average << " ms\n";
    
    return 0;
}
