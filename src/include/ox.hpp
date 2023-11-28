#ifndef OX_H
#define OX_H

#include "vehicle.hpp"

class Ox : public Vehicle {
private:

public:
    // Constructor: Creates a new Ox in the given Box2D world at the specified position (default at the origin)
    Ox(b2World* world, float x = 0, float y = 0, const std::string& imagePath = "../img/buffalo.png");

    // Destructor: Destroys the Box2D body associated with the Ox
    ~Ox();

    // Implement the SuperSkill function specific to the Ox
    void SuperSkill() override;
};

#endif // OX_H
