#ifndef COLLECTABLE_GOOD_HPP
#define COLLECTABLE_GOOD_HPP

#include "collectable.hpp"
#include <iostream>

class CollectableGood : public Collectable{
    public:
    CollectableGood(b2World* world, b2Vec2 position, float radius) : Collectable(world, position, radius){}

    void OnContact(Vehicle* car) override{
        std::cout << "hit" << std::endl;
        if (car != nullptr) {
            if (!this->getDelete()){
            car->BoostSpeed(20);
            std::cout<<"toBeDeleted"<<std::endl;
            this->setDelete();
            }
        }
    }
    
};

#endif