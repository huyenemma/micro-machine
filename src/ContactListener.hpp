#ifndef CONTACT_LISTENER_HPP
#define CONTACT_LISTENER_HPP

#include "collectable.hpp"
#include "collectableBad.hpp"
#include "../libs/include/Box2d/box2d.h"
#include "usertype.hpp"
#include <iostream>

class MyContactListener : public b2ContactListener{
public:
    void BeginContact(b2Contact* contact) override {
        std::cout<< "contact" << std::endl;
        HandleContact(contact, true);
    }

    void EndContact(b2Contact* contact) override {
        std::cout <<"end contact" << std::endl;
        HandleContact(contact, false);
    }

private:
    struct ContactData {
            b2Body* bodyA;
            b2Body* bodyB;
        };

    void HandleContact(b2Contact* contact, bool begin) {
        // Get the fixtures involved in the contact
        b2Fixture* fixtureA = contact->GetFixtureA();
        b2Fixture* fixtureB = contact->GetFixtureB();

        // Get the user data from the fixtures
        auto userDataA = reinterpret_cast<UserData*>(fixtureA->GetBody()->GetUserData().pointer);
        auto userDataB = reinterpret_cast<UserData*>(fixtureB->GetBody()->GetUserData().pointer);

        if (userDataA && userDataB) {
            
            std::cout<<"cast sucessfully"<<std::endl;
            // Check if one of the fixtures is a Vehicle and the other is a Collectable
            if ((IsVehicle(userDataA) && IsCollectable(userDataB)) ||
                (IsVehicle(userDataB) && IsCollectable(userDataA))) {
                // Handle the collision between Vehicle and Collectable

                Vehicle* vehicle = static_cast<Vehicle*>(IsVehicle(userDataA) ? userDataA->info.pointer : userDataB->info.pointer);
                CollectableBad* collectable = static_cast<CollectableBad*>(IsCollectable(userDataB) ? userDataB->info.pointer : userDataA->info.pointer);

                // Call the appropriate method in Vehicle and Collectable based on the contact type
                if (begin) {
                    std::cout<<"cast sucessfully"<<std::endl;
                    collectable->OnContact(); // Do something in the Collectable class
                }
            }
        }

    }
};





#endif