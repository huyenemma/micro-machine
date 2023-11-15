#ifndef BUFF_HPP
#define BUFF_HPP

#include <string> 
#include "vehicle.hpp"
#include "timer.hpp"

class Buff : public Timer {
private:
    std::string id; 
public:
    Buff(Vehicle* vehicle, std::string id ,int duration); 

    virtual ~Buff(){};

    virtual void ApplyEffect() = 0;

    virtual void ReverseEffect() = 0;
};

#endif
