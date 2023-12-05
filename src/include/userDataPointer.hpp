#ifndef USER_DATA_POINTER_HPP
#define USER_DATA_POINTER_HPP

#include <cstdint>

/**
 * @enum UserType
 * @brief Enumerates the possible types of user data.
 */
enum class UserType {
  Vehicle,      ///< User data corresponds to a Vehicle.
  Collectable,  ///< User data corresponds to a Collectable.
  Obstacle,     ///< User data corresponds to an Obstacle.
  OutsideArea   ///< User data corresponds to an OutsideArea.
};

/**
 * @union UserData
 * @brief Represents a union of data or a combination of type and pointer for
 * user data.
 */
union UserData {
  uintptr_t data;  ///< Raw data value.
  struct {
    UserType type;  ///< Type of user data.
    void* pointer;  ///< Pointer to user data.
  } info;           ///< Structure containing type and pointer information.
};

/**
 * @namespace BodyType
 * @brief Provides functions to check the type of user data.
 */
namespace BodyType {

/**
 * @brief Checks if the user data represents a Vehicle.
 * @param userData Pointer to user data.
 * @return True if the user data is of type Vehicle, false otherwise.
 */
bool IsVehicle(UserData* userData);

/**
 * @brief Checks if the user data represents a Collectable.
 * @param userData Pointer to user data.
 * @return True if the user data is of type Collectable, false otherwise.
 */
bool IsCollectable(UserData* userData);

/**
 * @brief Checks if the user data represents an Obstacle.
 * @param userData Pointer to user data.
 * @return True if the user data is of type Obstacle, false otherwise.
 */
bool IsObstacle(UserData* userData);

/**
 * @brief Checks if the user data represents an OutsideArea.
 * @param userData Pointer to user data.
 * @return True if the user data is of type OutsideArea, false otherwise.
 */
bool IsOutsideArea(UserData* userData);

}  // namespace BodyType

#endif  // USER_DATA_POINTER_HPP
