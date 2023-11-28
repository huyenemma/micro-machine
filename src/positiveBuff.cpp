#include "./include/positivebuff.hpp"
#include "./include/buff.hpp"
#include "vehicle.hpp"
using namespace PositiveBuff;

void OxSuperSkillBuff::ApplyEffect(Vehicle* vehicle){
    vehicle->ApplyBuff(buffIntensity,buffIntensity,1,0.001);
}

void OxSuperSkillBuff::ReverseEffect(Vehicle* vehicle){
    vehicle->ApplyBuff(1.0f/buffIntensity,1/buffIntensity,1,1.0f/0.001);
}

OxSuperSkillBuff::OxSuperSkillBuff(int duration,float Intensity) : Buff(duration,BuffType::Positive,BuffEffect::onetime) {
    buffIntensity = Intensity;
}

OxSuperSkillBuff::~OxSuperSkillBuff() {}
