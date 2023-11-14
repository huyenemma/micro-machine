#ifndef CONTACT_LISTENER_HPP
#define CONTACT_LISTENER_HPP

#include "collectable.hpp"
#include "../libs/include/Box2d/box2d.h"
#include "userDataPointer.hpp"
#include <iostream>
using namespace BodyType;
class MyContactListener : public b2ContactListener {
public:
    MyContactListener();
    void BeginContact(b2Contact* contact) override;

    void EndContact(b2Contact* contact) override;

    ~MyContactListener();

private:
    struct ContactData {
        b2Body* bodyA;
        b2Body* bodyB;
    };

    std::vector<ContactData> contactsToDelete;

    void HandleContact(b2Contact* contact, bool begin);  
};


#endif
