#include "./include/ox.hpp"
#include "../include/positivebuff.hpp"
#include <iostream>

constexpr float OX_MAX_SPEED = 4.0f;
constexpr float OX_ANGULAR_DAMPING = 0.95f;
constexpr float OX_BOOST_IMPULSE = 10.0f;
constexpr int OX_SKILL_COOLDOWN = 0;

Ox::Ox(b2World* world, float x /*= 0*/, float y /*= 0*/, const sf::Texture& texture)
    : Vehicle(world, x, y, texture)
{
    // Additional setup specific to the Ox with the Ox constants
    maxSpeed = OX_MAX_SPEED;
    m_body->SetAngularDamping(OX_ANGULAR_DAMPING);
    superSkillCoolDown = 120*FPS;
}

Ox::~Ox(){}

void Ox::SuperSkill()
{   
    PositiveBuff::OxSuperSkillBuff* buff = new PositiveBuff::OxSuperSkillBuff(10*FPS/10,1.5);
    this->AddBuff(buff);
}
