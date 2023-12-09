#include "./include/negativebuff.hpp"

#include "vehicle.hpp"
using namespace NegativeBuff;

void ReverseMushroom::ApplyEffect(Vehicle* vehicle) {
  vehicle->ApplyBuff(-1.0f * buffIntensity, 1 * buffIntensity,
                     1 * buffIntensity, -1.0f * buffIntensity);
}

void ReverseMushroom::ReverseEffect(Vehicle* vehicle) {
  vehicle->ApplyBuff(-1.0f / buffIntensity, 1 / buffIntensity,
                     1 / buffIntensity, -1.0f / buffIntensity);
}

ReverseMushroom::ReverseMushroom(int duration, float Intensity)
    : Buff(duration, BuffType::Negative, BuffEffect::onetime) {
  buffIntensity = Intensity;
}

ReverseMushroom::~ReverseMushroom() {}

// CrazyRotate buff
CrazyRotate::CrazyRotate(int duration, float degree, float intensity)
    : Buff(duration, BuffType::Negative, BuffEffect::continuous),
      degree_(degree),
      intensity_(intensity) {}

void CrazyRotate::ApplyEffect(Vehicle* vehicle) {
  vehicle->CrazyRotate(degree_, intensity_);
}

void CrazyRotate::ReverseEffect(Vehicle* vehicle) {}

CrazyRotate::~CrazyRotate() {}
