#ifndef NEGATIVE_BUFF_HPP
#define NEGATIVE_BUFF_HPP

#include <string> 
#include "buff.hpp"
#include "vehicle.hpp"

namespace NegativeBuff {
    class ReverseMushroom : public Buff{
    private:
        float buffIntensity;    
    public:
        ReverseMushroom(Vehicle* Vehicle,std::string id ,int duration,float Intensity);

        void ApplyEffect() override;

        void ReverseEffect() override;

        ~ReverseMushroom() override;

    };


}
#endif