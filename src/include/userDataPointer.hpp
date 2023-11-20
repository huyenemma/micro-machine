#ifndef USER_DATA_POINTER_HPP
#define USER_DATA_POINTER_HPP
#include <cstdint>

enum class UserType { Vehicle, Collectable, Obstacle, OutsideArea };

// TODO: manage union memory
union UserData {
  uintptr_t data;
  struct {
    UserType type;
    void* pointer;
  } info;
};

namespace BodyType {
bool IsVehicle(UserData* userData);
bool IsCollectable(UserData* userData);
bool IsObstacle(UserData* userData);
bool IsOutsideArea(UserData* userData);
}  // namespace BodyType

#endif