#ifndef COLLECTABLE_BAD_HPP
#define COLLECTABLE_BAD_HPP

#include "collectable.hpp"
#include <iostream>

class CollectableBad : public Collectable{
    public:
    CollectableBad(b2World* world, b2Vec2 position, float radius);

    void OnContact(Vehicle* car) override;
    
};

#endif