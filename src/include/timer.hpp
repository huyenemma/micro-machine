#ifndef TIMER_HPP
#define TIMER_HPP

#include <string>
#include <iostream>

class Timer {
private:
    std::string id;
    int timeLeft;

public:
    Timer(std::string id, int timeLeft):id(id),timeLeft(timeLeft){};

    virtual ~Timer(){};

    // Return true if the object should be removed, false otherwise
    bool Tick() {
        if (timeLeft > 0) {
            timeLeft--;
        }
        std::cout << "time left: " << timeLeft << std::endl;
        // Return true if timeLeft is zero, indicating that the object should be removed
        return (timeLeft == 0);
    }   
};

#endif
