#include "./include/ContactListener.hpp"

MyContactListener::MyContactListener() {}

void MyContactListener::BeginContact(b2Contact* contact) {
  std::cout << "contact" << std::endl;
  HandleContact(contact, true);
}

void MyContactListener::EndContact(b2Contact* contact) {
  std::cout << "end contact" << std::endl;
  HandleContact(contact, false);
}

void MyContactListener::HandleContact(b2Contact* contact, bool begin) {
  // Get the fixtures involved in the contact
  b2Fixture* fixtureA = contact->GetFixtureA();
  b2Fixture* fixtureB = contact->GetFixtureB();
  // Get the user data from the fixtures
  auto userDataA =
      reinterpret_cast<UserData*>(fixtureA->GetBody()->GetUserData().pointer);
  auto userDataB =
      reinterpret_cast<UserData*>(fixtureB->GetBody()->GetUserData().pointer);

  // Check if both fixtures have valid user data
  if (userDataA && userDataB) {
    std::cout << "cast sucessfully" << std::endl;
    // Check if one of the fixtures is a Vehicle and the other is a Collectable
    if ((IsVehicle(userDataA) && IsCollectable(userDataB)) ||
        (IsVehicle(userDataB) && IsCollectable(userDataA))) {
      // Handle the collision between Vehicle and Collectable

      Vehicle* vehicle =
          static_cast<Vehicle*>(IsVehicle(userDataA) ? userDataA->info.pointer
                                                     : userDataB->info.pointer);
      Collectable* collectable = static_cast<Collectable*>(
          IsCollectable(userDataB) ? userDataB->info.pointer
                                   : userDataA->info.pointer);

      // Call the appropriate method in Vehicle and Collectable based on the
      // contact type
      if (begin) {
        std::cout << "hit collectable" << std::endl;
        collectable->OnContact(
            vehicle);  // Do something in the Collectable class
      }
    } else if ((IsVehicle(userDataA) && IsObstacle(userDataB)) ||
               (IsVehicle(userDataB) && IsObstacle(userDataA))) {
      // Handle the collision between Vehicle and Obstacle

      Vehicle* vehicle =
          static_cast<Vehicle*>(IsVehicle(userDataA) ? userDataA->info.pointer
                                                     : userDataB->info.pointer);
      Obstacle* obstacle = static_cast<Obstacle*>(
          IsObstacle(userDataB) ? userDataB->info.pointer
                                : userDataA->info.pointer);

      // Call the appropriate method in Vehicle and Obstacle based on the
      // contact type
      if (begin) {
        std::cout << "hit obstacle" << std::endl;
        //obstacle->OnContact(vehicle);  // Do something in the Obstacle class
      }
    }
  }
}

MyContactListener::~MyContactListener() {}