#include "./include/ox.hpp"
#include "../include/positivebuff.hpp"
#include <iostream>

constexpr float OX_MAX_SPEED = 4.0f;
constexpr float OX_ANGULAR_DAMPING = 0.95f;
constexpr float OX_BOOST_IMPULSE = 10.0f;

constexpr int OX_SKILL_DURATION = 5*FPS;
constexpr int OX_SKILL_COOLDOWN = 5*FPS+OX_SKILL_DURATION;
constexpr int OX_SKILL_INTENSITY = 2.0f;

class OxSuperSkillBuff : public Buff{
    private:
        bool begin= true;
        float buffIntensity;
        std::string imagePath_;    
    public:
        OxSuperSkillBuff(int duration, float Intensity);

        void ApplyEffect(Vehicle* vehicle) override;

        void ReverseEffect(Vehicle* vehicle) override;

        ~OxSuperSkillBuff() override;
    };


void OxSuperSkillBuff::ApplyEffect(Vehicle* vehicle){
    if (begin) {
        vehicle->ApplyBuff(buffIntensity,buffIntensity,1,0.001);
        begin = false;
    }

    vehicle->ToggleForce(true);
}

void OxSuperSkillBuff::ReverseEffect(Vehicle* vehicle){
    vehicle->ApplyBuff(1.0f/buffIntensity,1/buffIntensity,1,1.0f/0.001);
}

OxSuperSkillBuff::OxSuperSkillBuff(int duration,float Intensity) : Buff(duration,BuffType::Positive,BuffEffect::continuous) {
    buffIntensity = Intensity;
}

OxSuperSkillBuff::~OxSuperSkillBuff() {}




Ox::Ox(b2World* world, float x /*= 0*/, float y /*= 0*/,const std::string& imagePath)
    : Vehicle(world, x, y,imagePath)
{
    // Additional setup specific to the Ox with the Ox constants
    maxSpeed = OX_MAX_SPEED;
    m_body->SetAngularDamping(OX_ANGULAR_DAMPING);
    superSkillCoolDown = 0;
}

Ox::~Ox(){}

void Ox::SuperSkill()
{   
    // Check if the super skill cooldown is not zero
    if (superSkillCoolDown == 0) {
        // Create an instance of OxSuperSkillBuff with the specified duration and intensity
        OxSuperSkillBuff* buff = new OxSuperSkillBuff(OX_SKILL_DURATION, OX_SKILL_INTENSITY);
        this->AddBuff(buff);

        // Set the cooldown for the next use
        superSkillCoolDown = OX_SKILL_COOLDOWN;
    } else {
        // Display a message or take some action indicating the cooldown is still active
        std::cout << "Ox's super skill is on cooldown!" << std::endl;
        // You can add additional logic here as needed
    }
}



