#ifndef CAT_H
#define CAT_H
#include "box2dInclude.hpp"
#include "vehicle.hpp"

class Cat : public Vehicle {
private:
    int superSkillCoolDown; // Follow camelCase for variable names

public:
    Cat(b2World* world, float x, float y, const sf::Texture& texture);

    ~Cat();

    void SuperSkill() override;
};
#endif