#include "./include/cat.hpp"
#include "../include/positivebuff.hpp"

constexpr float CAT_MAX_SPEED = 3.75f;
constexpr float CAT_ANGULAR_DAMPING = 0.8f;
constexpr int CAT_SKILL_COOLDOWN = 3 * FPS;

Cat::Cat(b2World* world, float x /*= 0*/, float y /*= 0*/, const std::string& imagePath)
    : Vehicle(world, x, y, imagePath)
{
    maxSpeed = CAT_MAX_SPEED;
    m_body->SetAngularDamping(CAT_ANGULAR_DAMPING);
    superSkillCoolDown = CAT_SKILL_COOLDOWN;
}

Cat::~Cat() {}

void Cat::SuperSkill()
{
    // Check if the super skill cooldown is not zero
    if (superSkillCoolDown == 0) {
        // Iterate through the buffs vector and remove negative buffs
        std::vector<Buff*>::iterator it = buffs.begin();
        while (it != buffs.end()) {
            if ((*it)->IsNegativeBuff()) {
                // Reverse the effect, delete the buff, and erase it from the vector
                (*it)->ReverseEffect(this);
                delete *it;
                it = buffs.erase(it);
            } else {
                // Move to the next element in the vector
                ++it;
            }
        }

        // Set the cooldown for the next use
        superSkillCoolDown = CAT_SKILL_COOLDOWN;
    } else {
        // Display a message or take some action indicating the cooldown is still active
        std::cout << "Cat's super skill is on cooldown!" << std::endl;
        // You can add additional logic here as needed
    }
}