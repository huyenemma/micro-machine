#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "box2dInclude.hpp"
#include "constant.hpp"
#include "vehicle.hpp"
#include "collectable.hpp"

class World {
 private:
  b2World* physicWorld;
  std::vector<Vehicle*> vehicles;
  std::vector<Collectable*> collectables;

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
  b2World* GetPhysicWorld() const;
  std::vector<Vehicle*>& GetVehicle();
  std::vector<Collectable*>& GetCollectable();
};

#endif  // WORLD_H