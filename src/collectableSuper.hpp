#ifndef COLLECTABLE_SUPER_H
#define COLLECTABLE_SUPER_H

#include "collectable.hpp"


class CollectableSuper : public Collectable{
    public:
    CollectableSuper(b2World* world, b2Vec2 position, float radius) : Collectable(world, position, radius) {}

    void OnContact(b2Body* carBody){
        // Assuming the car body is passed as a parameter to the method
        if (carBody) {
            // Increase the car's speed or apply other game logic
            //carBody->UpdateMaxSpeed();
        }

        // Delete the collectable
        Collectable::OnContact();
    }  
};

#endif