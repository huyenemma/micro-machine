#ifndef COLLECTABLE_SUPER_HPP
#define COLLECTABLE_SUPER_HPP

#include "collectable.hpp"
#include <iostream>

class CollectableSuper : public Collectable{
    public:
    CollectableSuper(b2World* world, b2Vec2 position, float radius);

    void OnContact(Vehicle* car) override;
    
};

#endif