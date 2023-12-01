
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
}
#endif