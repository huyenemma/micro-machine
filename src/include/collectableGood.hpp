#ifndef COLLECTABLE_GOOD_H
#define COLLECTABLE_GOOD_H

#include "box2d/box2D.h"
#include "collectable.hpp"

class CollectableGood : public Collectable {
 public:
  CollectableGood(b2World* world, b2Vec2 position, float radius, float boost)
      : Collectable(world, position, radius), boost_(boost) {}

  void OnContact(b2Body* carBody) {
    // Assuming the car body is passed as a parameter to the method
    if (carBody) {
      // Increase the car's speed or apply other game logic
      b2Vec2 impulse(0.0f, boost_);  // Adjust the impulse as needed
      carBody->ApplyLinearImpulse(impulse, carBody->GetWorldCenter(), true);
    }

    // Delete the collectable
    Collectable::OnContact();
  }

 private:
  float boost_;
};

#endif