#ifndef COLLECTABLE_BAD_H
#define COLLECTABLE_BAD_H

#include "collectable.hpp"
#include <Box2D/Box2D.h>

class CollectableBad: public Collectable{
    public:
    CollectableBad(b2World* world, b2Vec2 position, float radius, float decrease) : Collectable(world, position, radius), decrease_(decrease) {}

    void OnContact(b2Body* carBody){
        // Assuming the car body is passed as a parameter to the method
        if (carBody) {
            // Increase the car's speed or apply other game logic
            b2Vec2 impulse(0.0f, decrease_); // Adjust the impulse as needed
            carBody->ApplyLinearImpulse(impulse, carBody->GetWorldCenter(), true);
        }

        // Delete the collectable
        Collectable::OnContact();
    }

    private:
    float decrease_;
    
};

#endif