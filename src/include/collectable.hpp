#ifndef COLLECTABLE_H
#define COLLECTABLE_H

#include "box2dInclude.hpp"
#include "vehicle.hpp"
#include <utility>
#include <iostream>
#include "userDataPointer.hpp"
#include "vehicle.hpp"

using namespace BodyType;
class Collectable{
public:
    Collectable(b2World* world, b2Vec2 position, float radius);

    std::pair<float, float> GetPosition();

    void DeleteBody();

    float GetRadius();

    bool IsNullBody();

    void setDelete();

    bool getDelete();
    
    virtual void OnContact(Vehicle* car) = 0;

    
private:
    b2Body* body;
    float radius_;
    bool  toBeDeleted=false;
};

#endif