#ifndef CONTACT_LISTENER_HPP
#define CONTACT_LISTENER_HPP

#include <iostream>

#include "box2dInclude.hpp"
#include "collectable.hpp"
#include "obstacle.hpp"
#include "outsideArea.hpp"
#include "userDataPointer.hpp"
using namespace BodyType;
class MyContactListener : public b2ContactListener {
 public:
  MyContactListener();
  void BeginContact(b2Contact* contact) override;

  void EndContact(b2Contact* contact) override;

  ~MyContactListener();

 private:
  struct ContactData {
    b2Body* bodyA;
    b2Body* bodyB;
  };

  std::vector<ContactData> contactsToDelete;

  void HandleContact(b2Contact* contact, bool begin);
};

#endif
