
#ifndef POSITIVE_BUFF_HPP
#define POSITIVE_BUFF_HPP

#include <string> 
#include "buff.hpp"
#include "timer.hpp"

namespace PositiveBuff {
    class OxSuperSkillBuff : public Buff{
    private:
        float buffIntensity;
        std::string imagePath_;    
    public:
        OxSuperSkillBuff(int duration, float Intensity);

        void ApplyEffect(Vehicle* vehicle) override;

        void ReverseEffect(Vehicle* vehicle) override;

        ~OxSuperSkillBuff() override;
    };


}
#endif