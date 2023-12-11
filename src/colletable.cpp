#include <iostream>

#include "./include/collectable.hpp"

Collectable::Collectable(b2World* world, b2Vec2 position, float radius,
                         Buff* buff, const sf::Texture& texture)
    : radius_(radius), buff(buff), texture_(texture) {
  sprite_.setTexture(texture_);
  rescaleSprite(sprite_, radius_ * SCALE, radius_ * SCALE);

  // Define the collectable's shape
  b2CircleShape shape;
  shape.m_radius = radius;

  // Define the collectable's body definition
  b2BodyDef bodyDef;
  bodyDef.type = b2_staticBody;
  bodyDef.position.Set(position.x, position.y);

  // Create the collectable's body
  body = world->CreateBody(&bodyDef);

  // Create the fixture for the collectable
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &shape;
  fixtureDef.isSensor =
      true;  // Make the fixture a sensor to trigger contact without collision

  body->CreateFixture(&fixtureDef);

  // Set a custom user data to identify the collectable
  UserData* data = new UserData();  // Allocate UserData on the heap
  data->info.type = UserType::Collectable;
  data->info.pointer = this;
  body->GetUserData().pointer = reinterpret_cast<uintptr_t>(data);
}

std::pair<float, float> Collectable::GetPosition() const {
  b2Vec2 position = body->GetWorldCenter();
  return std::make_pair(position.x, position.y);
}

void Collectable::DeleteBody() {
  if ((body != nullptr) && toBeDeleted) {
    body->GetWorld()->DestroyBody(body);
    body = nullptr;
  }
}

float Collectable::GetRadius() { return radius_; }

bool Collectable::IsNullBody() { return body == nullptr; }

void Collectable::setDelete() { toBeDeleted = true; }

bool Collectable::getDelete() { return toBeDeleted; }

void Collectable::draw(sf::RenderTarget& target,
                       sf::RenderStates states) const {
  auto pos = GetPosition();
  sprite_.setPosition(pos.first * SCALE, pos.second * SCALE);

  sf::Vector2f spriteOrigin(sprite_.getLocalBounds().width / 2,
                            sprite_.getLocalBounds().height / 2);
  sprite_.setOrigin(spriteOrigin);

  float angleDegrees = body->GetAngle() * (180 / b2_pi);
  sprite_.setRotation(angleDegrees);

  target.draw(sprite_, states);
}

void Collectable::OnContact(Vehicle* vehicle) {
  // Your implementation here
  // For example, apply the buff to the vehicle
  if (vehicle != nullptr && buff != nullptr) {
    // Add sound effect
    if (!hitBuffer.loadFromFile("../sound/collectable.mp3")) {
      // Handle error loading sound files
      std::cerr << "Error loading sound files!" << std::endl;
    }
    hit.setBuffer(hitBuffer);
    hit.play();

    // handel contact on vehicle
    std::cout << "Added Buff" << std::endl;
    vehicle->AddBuff(buff);

    if (!this->getDelete()) {
      std::cout << "toBeDeleted" << std::endl;
      this->setDelete();
    }
  }
}