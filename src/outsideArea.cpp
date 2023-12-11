#include "outsideArea.hpp"

OutsideArea::OutsideArea(b2World* world, b2Vec2 position, float height,
                         float width)
    : height_(height), width_(width) {
  // Define area shape
  b2BodyDef bodyDef;
  body = world->CreateBody(&bodyDef);

  b2PolygonShape polygonShape;
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &polygonShape;
  // Set friction in this outside area
  fixtureDef.friction = 1;
  fixtureDef.isSensor = true;

  polygonShape.SetAsBox(width_ / 2, height_ / 2, position, 0);
  b2Fixture* groundAreaFixture = body->CreateFixture(&fixtureDef);
  UserData* data = new UserData();  // Allocate UserData on the heap
  data->info.type = UserType::OutsideArea;
  data->info.pointer = this;
  body->GetUserData().pointer = reinterpret_cast<uintptr_t>(data);
}

std::pair<float, float> OutsideArea::GetPosition() const {
  b2Vec2 position = body->GetWorldCenter();
  return std::make_pair(position.x, position.y);
}

void OutsideArea::DeleteBody() {
  if ((body != nullptr)) {
    std::cout << "Deleted" << std::endl;
    body->GetWorld()->DestroyBody(body);
    body = nullptr;
  }
}

std::pair<float, float> OutsideArea::GetDimension() {
  return std::make_pair(width_, height_);
}

bool OutsideArea::IsNullBody() { return body == nullptr; }

void OutsideArea::OnContact(Vehicle* car) {
  std::cout << "Out of track" << std::endl;
}
