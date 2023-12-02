#ifndef TIMER_HPP
#define TIMER_HPP

#include <string>
#include <iostream>

class Timer {
private:
    int timeLeft;

public:
    Timer(int timeLeft);

    virtual ~Timer(){};

    // Return true if the object should be removed, false otherwise
    bool Tick(); 
};

#endif
