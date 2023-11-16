#include "./include/negativebuff.hpp"

using namespace NegativeBuff;

void ReverseMushroom::ApplyEffect(){
    vehicle->ApplyBuff(-1.0f*buffIntensity,1*buffIntensity,1*buffIntensity,-1.0f*buffIntensity);
}

void ReverseMushroom::ReverseEffect(){
    vehicle->ApplyBuff(-1.0f/buffIntensity,1/buffIntensity,1/buffIntensity,-1.0f/buffIntensity);
}

ReverseMushroom::ReverseMushroom(Vehicle* vehicle,std::string id,int duration,float Intensity):Buff(vehicle,id,duration) {
    buffIntensity = Intensity;
}

ReverseMushroom::~ReverseMushroom() {
    
}