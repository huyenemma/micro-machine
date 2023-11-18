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
        ReverseMushroom(std::string id, int duration, float Intensity, const std::string& imagePath);

        void ApplyEffect(Vehicle* vehicle) override;

        void ReverseEffect(Vehicle* vehicle) override;

        ~ReverseMushroom() override;

    };


}
#endif