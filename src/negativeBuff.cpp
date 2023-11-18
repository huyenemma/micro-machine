#include "./include/negativebuff.hpp"
#include "vehicle.hpp"
using namespace NegativeBuff;

void ReverseMushroom::ApplyEffect(Vehicle* vehicle){
    vehicle->ApplyBuff(-1.0f*buffIntensity,1*buffIntensity,1*buffIntensity,-1.0f*buffIntensity);
}

void ReverseMushroom::ReverseEffect(Vehicle* vehicle){
    vehicle->ApplyBuff(-1.0f/buffIntensity,1/buffIntensity,1/buffIntensity,-1.0f/buffIntensity);
}

ReverseMushroom::ReverseMushroom(std::string id,int duration,float Intensity):Buff(id,duration) {
    buffIntensity = Intensity;
}

ReverseMushroom::~ReverseMushroom() {
    
}