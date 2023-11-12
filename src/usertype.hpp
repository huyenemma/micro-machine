#ifndef USER_HPP
#define USER_HPP

#include "../libs/include/Box2d/box2d.h"

enum class UserType { Vehicle, Collectable };

union UserData {
    uintptr_t data;
    struct {
        UserType type;
        void* pointer;
    } info;
};

bool IsVehicle(UserData userData) {
    return userData.info.type == UserType::Vehicle;
}

bool IsCollectable(UserData userData) {
    return userData.info.type == UserType::Collectable;
}

#endif