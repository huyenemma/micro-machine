#include "obstacle.hpp"

Obstacle::Obstacle(b2World* world, b2Vec2 position, float radius,
                   const std::string& imagePath)
    : radius_(radius), imagePath_(imagePath) {
  texture.loadFromFile(imagePath_);
  sprite.setTexture(texture);
  rescaleSprite(sprite, radius_ * SCALE, radius_ * SCALE);

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

std::pair<float, float> Obstacle::GetPosition() const {
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

void Obstacle::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  auto pos = GetPosition();
  sprite.setPosition(pos.first * SCALE, pos.second * SCALE);

  float angleDegrees = body->GetAngle() * (180 / b2_pi);
  sprite.setRotation(angleDegrees);

  target.draw(sprite, states);
}
/*
void Obstacle::OnContact(Vehicle* car) {
  std::cout << "hit obstacle" << std::endl;
  if (car != nullptr) {
    //Add sound effect
        if (!hitBuffer.loadFromFile("../sound/obstacle.mp3")) {
            // Handle error loading sound files
            std::cerr << "Error loading sound files!" << std::endl;
        }
        hit.setBuffer(hitBuffer);
        hit.setVolume(50);
        hit.play();

    //handle contact on vehicle
    car->CrazyRotate(1, 2);
  }
}
*/