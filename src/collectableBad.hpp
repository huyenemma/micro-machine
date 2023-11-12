#ifndef COLLECTABLE_BAD_HPP
#define COLLECTABLE_BAD_HPP

#include "collectable.hpp"
#include <iostream>



class CollectableBad : public Collectable{
    public:
    CollectableBad(b2World* world, b2Vec2 position, float radius, float decrease) : Collectable(world, position, radius), decrease_(decrease) {}

    void OnContact(Vehicle* carBody) override{
        if (carBody != nullptr) {
            // Increase the car's speed or apply other game logic
            std::cout << "hit" << std::endl;
            b2Vec2 impulse(0.0f, -decrease_*carBody->GetMass()); // Adjust the impulse as needed
            carBody->CollectableHit(impulse);
            this->Collected();
        }
        
    }

    private:
    float decrease_;
    
};

#endif