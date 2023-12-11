/**
 * @file constants.h
 * @brief Header file defining various constants used in the game.
 *
 * This file contains definitions of constants used throughout the game,
 * including physics parameters, game settings, vehicle properties, and more.
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

/// SCALE is used to convert between pixels and meters in the game world.
/// For example, 100 pixels are equivalent to 1 meter in the game.
const float SCALE = 100.0f;

/// Game constants
const int FPS = 24; ///< Frames per second for the game's simulation.
const float timeStep = 1.0f / FPS; ///< Time step for the physics simulation (in seconds).
const int velocityIterations = 8; ///< Number of iterations for velocity corrections in physics simulation.
const int positionIterations = 3; ///< Number of iterations for position corrections in physics simulation.
const float zoomCoef = 0.25; ///< Zoom coefficient for the game's camera.
const int winCondition = 3; ///< Number of rounds or conditions needed to win the game.

/// Vehicle constants
constexpr float MAX_SPEED = 4.0f; ///< Maximum speed of the vehicle.
constexpr float LINEAR_DAMPING = 0.9f; ///< Linear damping (resistance) affecting the vehicle's movement.
constexpr float ANGULAR_DAMPING = 0.9f; ///< Angular damping (resistance) affecting the vehicle's rotation.
constexpr float BOX_WIDTH = 0.25f; ///< Width of the vehicle's bounding box (in meters).
constexpr float BOX_HEIGHT = 0.25f; ///< Height of the vehicle's bounding box (in meters).
constexpr float DENSITY = 1.0f; ///< Density of the vehicle (affects mass).
constexpr float FRICTION = 0.3f; ///< Friction coefficient of the vehicle.
constexpr float FORCE_MAGNITUDE = 1.0f; ///< Magnitude of the force applied for the vehicle's movement.
constexpr float MAX_LATERAL_IMPULSE = 3.0f; ///< Maximum lateral impulse that can be applied to the vehicle.


#endif // CONSTANTS_H
