#ifndef COLLECTABLE_BAD_HPP
#define COLLECTABLE_BAD_HPP

#include "collectable.hpp"
#include <iostream>

class CollectableBad : public Collectable{
    public:
    CollectableBad(b2World* world, b2Vec2 position, float radius) : Collectable(world, position, radius){}

    void OnContact(Vehicle* car) override{
        std::cout << "hit" << std::endl;
        if (car != nullptr) {
            if (!this->getDelete()){
            car->CrazyRotate(360, 20, 5);
            std::cout<<"toBeDeleted"<<std::endl;
            this->setDelete();
            }
        }
    }
    
};

#endif