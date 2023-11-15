#include "collectableSuper.hpp"

CollectableSuper::CollectableSuper(b2World* world, b2Vec2 position, float radius) : Collectable(world, position, radius){}

void CollectableSuper::OnContact(Vehicle* car){
    std::cout << "hit" << std::endl;
    if (car != nullptr) {
        if (!this->getDelete()){
        car->UpdateMaxSpeed(10);
        std::cout<<"toBeDeleted"<<std::endl;
        this->setDelete();
        }
    }
}