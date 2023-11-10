
#include "ox.hpp"
#include "../include/box2d/box2d.h"
#include <iostream>

constexpr float OX_MAX_SPEED = 4.0f;
constexpr float OX_ANGULAR_DAMPING = 0.95f;
constexpr float OX_BOOST_IMPULSE    = 7.0f;
constexpr int   OX_SKILL_COOLDOWN   = 5;

Ox::Ox(b2World* world, float x /*= 0*/, float y /*= 0*/)
    : Vehicle(world, x, y)
{
    // Additional setup specific to the Ox with the Ox constants
    maxSpeed = OX_MAX_SPEED;
    if(m_body) {
        m_body->SetAngularDamping(OX_ANGULAR_DAMPING);}
    else {
        std::cout<<"HERE"<<std::endl;
    }    
}

Ox::~Ox()
{
}

void Ox::SuperSkill()
{
    // Apply the linear impulse boost specific to the Ox
    if (SuperSkillCoolDown == 0 ) {
        b2Vec2 impulse(OX_BOOST_IMPULSE, 0.0f); // Assuming the impulse is applied along the x-axis
        m_body->ApplyLinearImpulse(impulse, m_body->GetWorldCenter(), true);
        SuperSkillCoolDown = OX_SKILL_COOLDOWN;
    }
}
