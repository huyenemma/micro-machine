#include "./include/cat.hpp"
#include "../include/positivebuff.hpp"
#include <iostream>

constexpr float CAT_MAX_SPEED = 3.75f;
constexpr float CAT_ANGULAR_DAMPING = 0.8f;
constexpr int CAT_SKILL_COOLDOWN = 100*FPS;

Cat::Cat(b2World* world, float x /*= 0*/, float y /*= 0*/,const std::string& imagePath)
    : Vehicle(world, x, y,imagePath)
{
    // Additional setup specific to the Ox with the Ox constants
    maxSpeed = CAT_MAX_SPEED;
    m_body->SetAngularDamping(CAT_ANGULAR_DAMPING);
    superSkillCoolDown = CAT_SKILL_COOLDOWN;
}

Cat::~Cat(){}

void Cat::SuperSkill()
{   
    std::vector<Buff*>::iterator it = buffs.begin();
    while (it != buffs.end()) {
        if ((*it)->IsNegativeBuff()) {
            (*it)->ReverseEffect(this);
            delete *it;  
            it = buffs.erase(it);
        } else {
            ++it;  
        }
    }
}