#include "./include/ContactListener.hpp"

MyContactListener::MyContactListener() {}

void MyContactListener::ModelElasticCollision(b2Body* bodyA, b2Body* bodyB) {
    // Calculate relative velocity
    b2Vec2 relativeVelocity = bodyB->GetLinearVelocity() - bodyA->GetLinearVelocity();

    // Calculate the normal vector (points from A to B)
    b2Vec2 normal = bodyB->GetPosition() - bodyA->GetPosition();
    normal.Normalize();

    // Calculate relative velocity along the normal
    float relativeSpeedAlongNormal = b2Dot(relativeVelocity, normal);

    // Calculate the coefficient of restitution (elasticity)
    float restitution = 0.5;

    // Calculate the impulse (change in velocity)
    float impulse = -(1 + restitution) * relativeSpeedAlongNormal /
                    (1 / bodyA->GetMass() + 1 / bodyB->GetMass());

    // Apply the impulse to both bodies
    bodyA->ApplyLinearImpulse(-impulse * normal, bodyA->GetWorldCenter(), true);
    bodyB->ApplyLinearImpulse(impulse * normal, bodyB->GetWorldCenter(), true);
}


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
      if (begin) {
        std::cout << "hit obstacle" << std::endl;
        //obstacle->OnContact(vehicle);  // Do something in the Obstacle class
      }
    } else if (IsVehicle(userDataA) && IsVehicle(userDataB)) {
      Vehicle* vehicleA = static_cast<Vehicle*>(userDataA->info.pointer);
      Vehicle* vehicleB = static_cast<Vehicle*>(userDataB->info.pointer);

      // Handle the collision between two vehicles
      if (begin) {
        std::cout << "hit vehicle" << std::endl;
        ModelElasticCollision(fixtureA->GetBody(),fixtureB->GetBody());
      }
  }
}}

MyContactListener::~MyContactListener() {}