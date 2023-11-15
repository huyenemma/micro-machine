#include "collectableGood.hpp"

CollectableGood::CollectableGood(b2World* world, b2Vec2 position, float radius) : Collectable(world, position, radius){}

void CollectableGood::OnContact(Vehicle* car){
    std::cout << "hit" << std::endl;
    if (car != nullptr) {
        if (!this->getDelete()){
        car->BoostSpeed(20);
        std::cout<<"toBeDeleted"<<std::endl;
        this->setDelete();
        }
    }
}
    
