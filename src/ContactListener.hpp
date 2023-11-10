#ifndef CONTACT_LISTENER_HPP
#define CONTACT_LISTENER_HPP

#include "collectable.hpp"
#include "../libs/include/Box2d/box2d.h"
#include <iostream>

class MyContactListener : public b2ContactListener {
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
        auto userDataA = fixtureA->GetBody()->GetUserData().pointer;
        auto userDataB = fixtureB->GetBody()->GetUserData().pointer;

        // Check if both fixtures have valid user data
        if (userDataA && userDataB) {
            // Check if one of the fixtures is a Vehicle and the other is a Collectable
            if ((IsVehicle(userDataA) && IsCollectable(userDataB)) ||
                (IsVehicle(userDataB) && IsCollectable(userDataA))) {
                // Handle the collision between Vehicle and Collectable
                Vehicle* vehicle = reinterpret_cast<Vehicle*>(IsVehicle(userDataA) ? userDataA : userDataB);
                Collectable* collectable = reinterpret_cast<Collectable*>(IsCollectable(userDataA) ? userDataA : userDataB);

                // Call the appropriate method in Vehicle and Collectable based on the contact type
                if (begin) {
                    collectable->OnContact(); // Do something in the Collectable class
                }
            }
        }
    }

    bool IsVehicle(uintptr_t userData) {
        std::cout << "called" << std::endl;
        return static_cast<Vehicle*>(reinterpret_cast<Vehicle*>(userData));
    }

    bool IsCollectable(uintptr_t userData) {
        std::cout << "called" << std::endl;
        return static_cast<Collectable*>(reinterpret_cast<Collectable*>(userData));
    }
};


#endif