#ifndef HORSE_H
#define HORSE_H
#include "vehicle.hpp"

class Horse : public Vehicle {
private:
    int superSkillCoolDown; // Follow camelCase for variable names

public:
    Horse(b2World* world, float x = 0, float y = 0, const std::string& imagePath = "../img/buffalo.png");

    ~Horse();

    void SuperSkill() override;
};
#endif