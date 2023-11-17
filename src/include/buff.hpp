
    #ifndef BUFF_HPP
    #define BUFF_HPP

    #include <string> 
    #include "timer.hpp"

    class Vehicle;
    
    enum buffType {
        onetime,
        continuous,
    };

    class Buff : public Timer {
    protected:
        std::string id; 
    public:
        Buff(std::string id ,int duration): Timer(id,duration) {}

        ~Buff(){};

        virtual void ApplyEffect(Vehicle* vehicle) = 0;

        virtual void ReverseEffect(Vehicle* vehicle) = 0;
    };

    #endif
