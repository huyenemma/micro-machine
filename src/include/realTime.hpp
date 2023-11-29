#ifndef REAL_TIME_HPP
#define REAL_TIME_HPP

#include <chrono>
#include <thread>

class RealTime{
    private: 
        int duration_;
        std::chrono::steady_clock::time_point startTime_;

    public:
    RealTime(int duration) : duration_(duration){}

    void SetUp() {
        // Set the duration of the game to specified minutes
        std::chrono::minutes gameDuration(duration_);

        // Get the current time point
        startTime_ = std::chrono::steady_clock::now();
    }

    bool IsTimeUp() {
        // Calculate the elapsed time
        auto currentTime = std::chrono::steady_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::minutes>(currentTime - startTime_);

        // Check if the game duration has passed
        return (elapsedTime >= std::chrono::minutes(duration_));
    }
};
#endif