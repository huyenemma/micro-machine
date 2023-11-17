#include "obstacle.hpp"

Obstacle::Obstacle(b2World* world, b2Vec2 position, float radius)
    : radius_(radius) {
  // Define the obstacle shape
  b2CircleShape shape;
  shape.m_radius = radius;

  // Define the obstacle body definition
  b2BodyDef bodyDef;
  bodyDef.type = b2_staticBody;
  bodyDef.position.Set(position.x, position.y);

  // Create the obstacle body
  body = world->CreateBody(&bodyDef);

  // Create the fixture for the obstacle
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &shape;
  fixtureDef.isSensor =
      true;  // Make the fixture a sensor to trigger contact without collision

  body->CreateFixture(&fixtureDef);

  // Set a custom user data to identify the obstacle
  // b2BodyUserData data = body->GetUserData();
  // uintptr_t uintptrValue = reinterpret_cast<uintptr_t>(this);
  // data.pointer = uintptrValue;
  UserData* data = new UserData();  // Allocate UserData on the heap
  data->info.type = UserType::Obstacle;
  data->info.pointer = this;
  body->GetUserData().pointer = reinterpret_cast<uintptr_t>(data);
}

std::pair<float, float> Obstacle::GetPosition() {
  b2Vec2 position = body->GetWorldCenter();
  return std::make_pair(position.x, position.y);
}

void Obstacle::DeleteBody() {
  if ((body != nullptr)) {
    std::cout << "Deleted" << std::endl;
    body->GetWorld()->DestroyBody(body);
    body = nullptr;
  }
}

float Obstacle::GetRadius() { return radius_; }

bool Obstacle::IsNullBody() { return body == nullptr; }

void Obstacle::OnContact(Vehicle* car) {
  std::cout << "hit" << std::endl;
  if (car != nullptr) {
    car->BoostSpeed(0.2);
  }
}