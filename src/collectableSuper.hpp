#ifndef COLLECTABLE_SUPER_HPP
#define COLLECTABLE_SUPER_HPP

#include "collectable.hpp"
#include <iostream>

class CollectableSuper : public Collectable{
    public:
    CollectableSuper(b2World* world, b2Vec2 position, float radius) : Collectable(world, position, radius){}

    void OnContact(Vehicle* car) override{
        std::cout << "hit" << std::endl;
        if (car != nullptr) {
            if (!this->getDelete()){
            car->UpdateMaxSpeed(10);
            std::cout<<"toBeDeleted"<<std::endl;
            this->setDelete();
            }
        }
    }
    
};

#endif