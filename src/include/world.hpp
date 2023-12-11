#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "box2dInclude.hpp"
#include "collectable.hpp"
#include "constant.hpp"
#include "obstacle.hpp"
#include "vehicle.hpp"
#include "checkpoint.hpp"

class World {
 private:
  b2World* physicWorld;
  StartLine* startLine;
  std::vector<Vehicle*> vehicles;
  std::vector<Collectable*> collectables;
  std::vector<Obstacle*> obstacles;
  Vehicle* winner;
  
 public:
  // contructor
  World(b2Vec2 gravity);
  // destructor
  ~World();
  // update the physics world
  void Update(float timeStep, int velocityIterations, int positionIterations);

  Vehicle* GetWinner();

  // add a vehicle to the world
  void AddVehicle(Vehicle* vehicle);

  void AddCollectable(Collectable* Collectable);

  void SetRacingTrack(StartLine* startline);

  void AddObstacle(Obstacle* Obstacle);

  std::map<Vehicle*,int> GetPoints();

  int GetPoint(Vehicle* car);

  bool HaveAnyOneWin();
  
  b2World* GetPhysicWorld() const;
  std::vector<Vehicle*>& GetVehicle();
  std::vector<Collectable*>& GetCollectable();
  std::vector<Obstacle*>& GetObstacle();
  
};

#endif  // WORLD_H