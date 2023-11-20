#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "box2dInclude.hpp"
#include "collectable.hpp"
#include "constant.hpp"
#include "obstacle.hpp"
#include "vehicle.hpp"

class World {
 private:
  b2World* physicWorld;
  std::vector<Vehicle*> vehicles;
  std::vector<Collectable*> collectables;
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

  void AddCollectable(Collectable* Collectable);

  void AddObstacle(Obstacle* Obstacle);
  b2World* GetPhysicWorld() const;
  std::vector<Vehicle*>& GetVehicle();
  std::vector<Collectable*>& GetCollectable();
  std::vector<Obstacle*>& GetObstacle();
};

#endif  // WORLD_H