#include "./include/timer.hpp"

Timer::Timer(int timeLeft):timeLeft(timeLeft){};

bool Timer::Tick() {
    if (timeLeft > 0) {
        timeLeft--;
    }
    std::cout << "time left: " << timeLeft << std::endl;
    // Return true if timeLeft is zero, indicating that the object should be removed
    return (timeLeft == 0);
}  