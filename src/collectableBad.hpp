#ifndef COLLECTABLE_BAD_HPP
#define COLLECTABLE_BAD_HPP

#include "collectable.hpp"



class CollectableBad: public Collectable{
    public:
    CollectableBad(b2World* world, b2Vec2 position, float radius, float decrease) : Collectable(world, position, radius), decrease_(decrease) {}

    void OnContact(b2Body* carBody){
        Vehicle* car = static_cast<Vehicle*>(carBody->GetUserData());
        if (car != nullptr) {
            // Increase the car's speed or apply other game logic
            b2Vec2 impulse(0.0f, decrease_); // Adjust the impulse as needed
            //car->ApplyLinearImpulse(impulse, carBody->GetWorldCenter(), true);
        }

        // Delete the collectable
        Collectable::OnContact();
    }

    private:
    float decrease_;
    
};

#endif