#include "./include/negativebuff.hpp"
#include "vehicle.hpp"
using namespace NegativeBuff;

void ReverseMushroom::ApplyEffect(Vehicle* vehicle){
    vehicle->ApplyBuff(-1.0f*buffIntensity,1*buffIntensity,1*buffIntensity,-1.0f*buffIntensity);
}

void ReverseMushroom::ReverseEffect(Vehicle* vehicle){
    vehicle->ApplyBuff(-1.0f/buffIntensity,1/buffIntensity,1/buffIntensity,-1.0f/buffIntensity);
}

ReverseMushroom::ReverseMushroom(std::string id,int duration,float Intensity) : Buff(id, duration) {
    buffIntensity = Intensity;
}

ReverseMushroom::~ReverseMushroom() {}

/*
//CrazyRotate buff
CrazyRotate::CrazyRotate(std::string id, int duration, float torque, float Intensity) : Buff(id,duration), buffIntensity(Intensity), torque_(torque){}

void CrazyRotate::ApplyEffect(Vehicle* vehicle){
    vehicle->CrazyRotate(torque_, buffIntensity);
}

void CrazyRotate::ReverseEffect(Vehicle* vehicle) {}

CrazyRotate::~CrazyRotate(){}
*/