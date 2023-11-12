#ifndef COLLECTABLE_HPP
#define COLLECTABLE_HPP

#include "../libs/include/Box2d/box2d.h"
#include "vehicle.hpp"
#include "usertype.hpp"
#include <utility>

class Collectable{
public:
    Collectable(b2World* world, b2Vec2 position, float radius) : radius_(radius){
        // Define the collectable's shape
        b2CircleShape shape;
        shape.m_radius = radius;

        // Define the collectable's body definition
        b2BodyDef bodyDef;
        bodyDef.type = b2_staticBody;
        bodyDef.position.Set(position.x, position.y);
    
        // Create the collectable's body
        body = world->CreateBody(&bodyDef);

        // Create the fixture for the collectable
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &shape;
        fixtureDef.isSensor = true; // Make the fixture a sensor to trigger contact without collision

        body->CreateFixture(&fixtureDef);

        UserData* data = new UserData(); // Allocate UserData on the heap
        data->info.type = UserType::Collectable;
        data->info.pointer = this;
        body->GetUserData().pointer = reinterpret_cast<uintptr_t>(data); 

    }

    std::pair<float, float> GetPosition(){
        b2Vec2 position = body->GetWorldCenter();
        return std::make_pair(position.x, position.y);
    }

    float GetRadius(){
        return radius_;
    }

    virtual void OnContact() = 0;

    bool IsNull(){
        return body == nullptr;
    }

    //flag to delete item
    void Collected(){hit = true;}

private:
    b2Body* body;
    float radius_;
    bool hit;
};

#endif