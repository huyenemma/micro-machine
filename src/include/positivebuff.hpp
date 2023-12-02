#ifndef POSITIVE_BUFF_HPP
#define POSITIVE_BUFF_HPP

#include <string> 
#include "buff.hpp"
#include "timer.hpp"

namespace PositiveBuff {
    class OxSuperSkillBuff : public Buff{
    private:
        float buffIntensity;
        
    public:
        OxSuperSkillBuff(int duration,float Intensity);

        void ApplyEffect(Vehicle* vehicle);

        void ReverseEffect(Vehicle* vehicle);

        ~OxSuperSkillBuff();
    };


    class MaxSpeed : public Buff{
    private:
    float boost_;
        
    public:
        MaxSpeed(int duration,float boost);

        void ApplyEffect(Vehicle* vehicle);

        void ReverseEffect(Vehicle* vehicle);

        ~MaxSpeed();
    };


    class Magnetic : public Buff{
    private:
    float radius_;
        
    public:
        Magnetic(int duration, float radius);

        void ApplyEffect(Vehicle* vehicle);

        void ReverseEffect(Vehicle* vehicle);

        ~Magnetic();
    };
}
#endif