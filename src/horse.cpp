#include "./include/horse.hpp"
#include "../include/buff.hpp"

constexpr float HORSE_MAX_SPEED = 4.5f;
constexpr float HORSE_ANGULAR_DAMPING = 0.7f;
constexpr int HORSE_SKILL_DURATION = 10 *FPS;
constexpr int HORSE_SKILL_COOLDOWN = 12 * FPS + HORSE_SKILL_DURATION;
constexpr int HORSE_SKILL_INTENSITY = 1.5f;

class HorseSuperSkillBuff : public Buff{
    private:
        float buffIntensity;
        std::string imagePath_;    
    public:
        HorseSuperSkillBuff(int duration, float Intensity);

        void ApplyEffect(Vehicle* vehicle) override;

        void ReverseEffect(Vehicle* vehicle) override;

        ~HorseSuperSkillBuff() override;
    };

void HorseSuperSkillBuff::ApplyEffect(Vehicle* vehicle){
    vehicle->ApplyBuff(buffIntensity,buffIntensity,1,1);
}

void HorseSuperSkillBuff::ReverseEffect(Vehicle* vehicle){
    vehicle->ApplyBuff(1.0f/buffIntensity,1/buffIntensity,1,1);
}

HorseSuperSkillBuff::HorseSuperSkillBuff(int duration,float Intensity) : Buff(duration,BuffType::Positive,BuffEffect::onetime) {
    buffIntensity = Intensity;
}

HorseSuperSkillBuff::~HorseSuperSkillBuff() {}


Horse::Horse(b2World* world, float x /*= 0*/, float y /*= 0*/, const std::string& imagePath)
    : Vehicle(world, x, y, imagePath)
{
    maxSpeed = HORSE_MAX_SPEED;
    m_body->SetAngularDamping(HORSE_ANGULAR_DAMPING);
    superSkillCoolDown = HORSE_SKILL_COOLDOWN;
}

Horse::~Horse() {}

void Horse::SuperSkill()
{
    if(superSkillCoolDown == 0 ) {
        HorseSuperSkillBuff* buff = new HorseSuperSkillBuff(HORSE_SKILL_DURATION,HORSE_SKILL_INTENSITY);
        AddBuff(buff);
        superSkillCoolDown =HORSE_SKILL_COOLDOWN;
    }
}