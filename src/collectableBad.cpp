#include "collectableBad.hpp"

CollectableBad::CollectableBad(b2World* world, b2Vec2 position, float radius) : Collectable(world, position, radius){}

void CollectableBad::OnContact(Vehicle* car){
    std::cout << "hit" << std::endl;
    if (car != nullptr) {
        if (!this->getDelete()){
            car->CrazyRotate(5, 20, 5);
            std::cout<<"toBeDeleted"<<std::endl;
            this->setDelete();
        }
    }
}