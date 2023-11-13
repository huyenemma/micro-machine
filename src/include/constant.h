#ifndef CONSTANTS_H
#define CONSTANTS_H

// Define SCALE to convert between pixels and meters
// Example: 100 pixels = 1 meter
const float SCALE = 100.0f;

// GAME
const int FPS =24;
const float timeStep = 1.0f/FPS;      //the length of time passed to simulate (seconds)
const int velocityIterations = 8;   //how strongly to correct velocity
const int positionIterations = 3;   //how strongly to correct position

// VEHICLE 
constexpr float MAX_SPEED = 20.0f;
constexpr float LINEAR_DAMPING = 0.6f;
constexpr float ANGULAR_DAMPING = 0.95f;
constexpr float BOX_WIDTH = 1.0f;
constexpr float BOX_HEIGHT = 1.0f;
constexpr float DENSITY = 1.0f;
constexpr float FRICTION = 0.3f;
constexpr float FORCE_MAGNITUDE = 5.0f;
#endif