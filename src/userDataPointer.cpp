#include "userDataPointer.hpp"

bool BodyType::IsVehicle(UserData* userData) {
  return userData->info.type == UserType::Vehicle;
};

bool BodyType::IsCollectable(UserData* userData) {
  return userData->info.type == UserType::Collectable;
};

bool BodyType::IsObstacle(UserData* userData) {
  return userData->info.type == UserType::Obstacle;
};
