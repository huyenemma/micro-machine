
#ifndef BUFF_HPP
#define BUFF_HPP

#include <string> 
#include "vehicle.hpp"
#include "timer.hpp"

enum buffType {
    onetime,
    continuous,
};

class Buff : public Timer {
protected:
    std::string id; 
    Vehicle* vehicle;
public:
    Buff(Vehicle* vehicle, std::string id ,int duration): Timer(id,duration){
        this->vehicle = vehicle;
    }; 

    virtual ~Buff(){};

    virtual void ApplyEffect() = 0;

    virtual void ReverseEffect() = 0;
};

#endif
