#ifndef CONTACT_LISTENER_HPP
#define CONTACT_LISTENER_HPP

#include "collectable.hpp"
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
    void HandleContact(b2Contact* contact, bool begin) {
        // Get the fixtures involved in the contact
        b2Fixture* fixtureA = contact->GetFixtureA();
        b2Fixture* fixtureB = contact->GetFixtureB();

        // Get the user data from the fixtures
        UserData userDataA;
        userDataA.data = fixtureA->GetBody()->GetUserData().pointer;
        UserData userDataB;
        userDataB.data = fixtureB->GetBody()->GetUserData().pointer;

        // Check if both fixtures have valid user data
        if (userDataA.data && userDataB.data) {
            // Handle the collision between Vehicle and Collectable
            Collectable* collectable = nullptr;
            Vehicle* vehicle = nullptr;
            
            if (userDataA.info.type == UserType::Collectable) {
                std::cout << "A is collectable" << std::endl;
                collectable = (Collectable*) userDataA.info.pointer;
                vehicle = (Vehicle*) userDataB.info.pointer;
            } else if (userDataA.info.type == UserType::Vehicle){
                collectable = (Collectable*) userDataB.info.pointer;
                vehicle = (Vehicle*)userDataA.info.pointer;
            }
            
            // Call the appropriate method in Vehicle and Collectable based on the contact type
            if (collectable && vehicle && begin) {
                std::cout << "hihi" << std::endl;
                collectable->OnContact(vehicle); 
            }
            
        }
    }
};





#endif