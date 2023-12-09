#include "./include/positivebuff.hpp"

#include "./include/buff.hpp"
#include "vehicle.hpp"

using namespace PositiveBuff;

// OxSuperSkill
void OxSuperSkillBuff::ApplyEffect(Vehicle* vehicle) {
  vehicle->ApplyBuff(buffIntensity, buffIntensity, 1, 0.001);
}

void OxSuperSkillBuff::ReverseEffect(Vehicle* vehicle) {
  vehicle->ApplyBuff(1.0f / buffIntensity, 1 / buffIntensity, 1, 1.0f / 0.001);
}

OxSuperSkillBuff::OxSuperSkillBuff(int duration, float Intensity)
    : Buff(duration, BuffType::Positive, BuffEffect::onetime) {
  buffIntensity = Intensity;
}

OxSuperSkillBuff::~OxSuperSkillBuff() {}

// MaxSpeed
MaxSpeed::MaxSpeed(int duration, float boost)
    : Buff(duration, BuffType::Positive, BuffEffect::continuous),
      boost_(boost) {}

void MaxSpeed::ApplyEffect(Vehicle* vehicle) {
  vehicle->ApplyBuff(1, boost_, 1, 1);
}

void MaxSpeed::ReverseEffect(Vehicle* vehicle) {
  vehicle->ApplyBuff(1, 1 / boost_, 1, 1);
}

MaxSpeed::~MaxSpeed() {}

// Magnetic Pull
Magnetic::Magnetic(int duration, float radius)
    : Buff(duration, BuffType::Positive, BuffEffect::continuous),
      radius_(radius) {}

void Magnetic::ApplyEffect(Vehicle* vehicle) { vehicle->MagneticPull(radius_); }

void Magnetic::ReverseEffect(Vehicle* vehicle) {
  vehicle->ReverseMagneticPull();
}

Magnetic::~Magnetic() {}