#ifndef COLLECTABLE_GOOD_HPP
#define COLLECTABLE_GOOD_HPP

#include "collectable.hpp"
#include <iostream>

class CollectableGood : public Collectable{
    public:
    CollectableGood(b2World* world, b2Vec2 position, float radius);
    void OnContact(Vehicle* car) override;
    
};

#endif