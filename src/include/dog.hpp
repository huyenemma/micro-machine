#ifndef DOG_H
#define DOG_H
#include "../include/box2d/box2d.h"
#include "vehicle.hpp"

class Dog : public Vehicle {
private:
    int superSkillCoolDown; // Follow camelCase for variable names

public:
    // Constructor: Creates a new Ox in the given Box2D world at the specified position (default at the origin)
    Dog(b2World* world, float x = 0, float y = 0, const std::string& imagePath = "../img/buffalo.png");

    // Destructor: Destroys the Box2D body associated with the Ox
    ~Dog();

    // Implement the SuperSkill function specific to the Ox
    void SuperSkill() override;
};
#endif