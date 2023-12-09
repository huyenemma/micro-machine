#ifndef CONSTANTS_H
#define CONSTANTS_H

// Define SCALE to convert between pixels and meters
// Example: 100 pixels = 1 meter
const float SCALE = 100.0f;

// GAME
const int FPS = 24;
const float timeStep =
    1.0f / FPS;  // the length of time passed to simulate (seconds)
const int velocityIterations = 8;  // how strongly to correct velocity
const int positionIterations = 3;  // how strongly to correct position
const float zoomCoef = 0.2f;
const int winCondition = 6;

// VEHICLE
constexpr float MAX_SPEED = 4.0f;
constexpr float LINEAR_DAMPING = 0.9f;
constexpr float ANGULAR_DAMPING = 0.9f;
constexpr float BOX_WIDTH = 0.25f;
constexpr float BOX_HEIGHT = 0.25f;
constexpr float DENSITY = 1.0f;
constexpr float FRICTION = 0.3f;
constexpr float FORCE_MAGNITUDE = 1.0f;
constexpr float MAX_LATERAL_IMPULSE = 3.0f;

// NegativeBuff

#endif