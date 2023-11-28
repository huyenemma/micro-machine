#ifndef CAT_H
#define CAT_H
#include "vehicle.hpp"

class Cat : public Vehicle {
private:
    int superSkillCoolDown; // Follow camelCase for variable names

public:
    Cat(b2World* world, float x = 0, float y = 0, const std::string& imagePath = "../img/buffalo.png");

    ~Cat();

    void SuperSkill() override;
};
#endif