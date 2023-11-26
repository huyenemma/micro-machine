
    #ifndef BUFF_HPP
    #define BUFF_HPP

    #include <string> 
    #include "timer.hpp"

    class Vehicle;
    
    enum BuffEffect {
        onetime,
        continuous,
    };

    enum class BuffType {
        Positive,
        Negative
    };

    class Buff : public Timer {
    protected:
        std::string id; 
        BuffType type_;
        BuffEffect effectType_;
        
    public:
        Buff(int duration,BuffType type,BuffEffect effectType): Timer(duration) ,type_(type), effectType_(effectType) {}

        ~Buff(){};

        virtual void ApplyEffect(Vehicle* vehicle) = 0;

        virtual void ReverseEffect(Vehicle* vehicle) = 0;

        bool IsContinuous() {
            return (effectType_ == BuffEffect::continuous);
        };

        bool IsNegativeBuff() {
            return (type_ == BuffType::Negative);
        }
    };

    #endif
