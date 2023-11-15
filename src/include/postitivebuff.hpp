
#ifndef BUFF_HPP
#define BUFF_HPP

#include <string> 
#include "buff.hpp"
#include "timer.hpp"
#include "vehicle.hpp"

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