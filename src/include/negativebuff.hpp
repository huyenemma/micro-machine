#ifndef NEGATIVE_BUFF_HPP
#define NEGATIVE_BUFF_HPP

#include <string> 
#include "buff.hpp"

namespace NegativeBuff {
    class ReverseMushroom : public Buff{
    private:
        float buffIntensity;
        std::string imagePath_;    
    public:
        ReverseMushroom(int duration, float Intensity);

        void ApplyEffect(Vehicle* vehicle) override;

        void ReverseEffect(Vehicle* vehicle) override;

        ~ReverseMushroom() override;
    };


    class CrazyRotate : public Buff{
    private:
        float buffIntensity;  
        float torque_;

    public:
        CrazyRotate(std::string id ,int duration, float torque, float Intensity);

        void ApplyEffect(Vehicle* vehicle) override;

        void ReverseEffect(Vehicle* vehicle) override;

        ~CrazyRotate() override;
    };

    


}
#endif