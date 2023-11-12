#ifndef COLLECTABLE_GOOD_HPP
#define COLLECTABLE_GOOD_HPP

#include "collectable.hpp"
#include <iostream>


class CollectableGood : public Collectable{
    public:
    CollectableGood(b2World* world, b2Vec2 position, float radius, float boost) : Collectable(world, position, radius), boost_(boost) {}

    void OnContact(Vehicle* carBody) override{
        std::cout << "hit" << std::endl;
        //Vehicle* vehicle = reinterpret_cast<Vehicle*>(carBody->GetUserData().pointer);
        
        if (carBody != nullptr) {
            // Increase the car's speed or apply other game logic
            b2Vec2 impulse(0.0f, boost_*carBody->GetMass()); // Adjust the impulse as needed
            carBody->CollectableHit(impulse);
            this->Collected();
        }
    }
    private:
    float boost_;
    
};

#endif