#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "box2dInclude.hpp"
#include "constant.hpp"
#include "obstacle.hpp"
#include "vehicle.hpp"

class World {
 private:
  b2World* physicWorld;
  std::vector<Vehicle*> vehicles;
  std::vector<Obstacle*> obstacles;

 public:
  // contructor
  World(b2Vec2 gravity);
  // destructor
  ~World();
  // update the physics world
  void Update(float timeStep, int velocityIterations, int positionIterations);

  // add a vehicle to the world
  void AddVehicle(Vehicle* vehicle);
  b2World* GetPhysicWorld() const;
  std::vector<Vehicle*>& GetVehicle();

  // add a obstacle to the world
  void AddObstacle(Obstacle* obstacle);
  std::vector<Obstacle*>& GetObstacle();
};

#endif  // WORLD_H