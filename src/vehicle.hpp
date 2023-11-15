
#ifndef VEHICLE_H
#define VEHICLE_H
#include "../libs/include/Box2d/box2d.h"




// Class representing a simple vehicle in a 2D physics world using Box2D
class Vehicle
{
protected:
    bool forceOn;   // Flag indicating whether a force is applied to the vehicle
    b2Body* m_body; // Box2D body representing the vehicle
    float maxSpeed;  // Maximum speed of the vehicle
    
    

public:
    // Constructor: Creates a new vehicle in the given Box2D world at the specified position (default at the origin)
    Vehicle(b2World* world, float x = 0, float y = 0);

    // Destructor: Destroys the Box2D body associated with the vehicle
    ~Vehicle();

    // Update the speed of the vehicle based on applied force
    void UpdateSpeed();

    // Rotate the vehicle by applying angular impulse (default torque is 1)
    void Rotate(float torque = 1);

    // Get the current position of the vehicle
    std::pair<float, float> GetPosition();

    // Toggle the force applied to the vehicle on/off
    void ToggleForce(bool value);

    // Get the current angle of the vehicle
    float GetAngle();

    // Placeholder function for processing items (to be implemented as needed)
    void ProcessItem();

    // A skill particular to each vehicle
    void BoostSpeed(float boost);

    void CrazyRotate(float torque, float boost, int times);

    float GetMass();

    void UpdateMaxSpeed(float speed);

};

#endif // VEHICLE_H
