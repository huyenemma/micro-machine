#ifndef HORSE_H
#define HORSE_H
#include "../include/box2d/box2d.h"
#include "vehicle.hpp"

class Horse : public Vehicle {
private:
    int superSkillCoolDown; // Follow camelCase for variable names

public:
    Horse(b2World* world, float x , float y , const sf::Texture& texture);

    ~Horse();

    void SuperSkill() override;
};
#endif