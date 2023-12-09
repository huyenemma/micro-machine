#include "./include/world.hpp"

World::World(b2Vec2 gravity) { physicWorld = new b2World(gravity); };

World::~World() {
  delete physicWorld;

  for (auto vehicle : vehicles) {
    delete vehicle;
  }

  vehicles.clear();
}

void World::Update(float timeStep, int velocityIterations,
                   int positionIterations) {
  physicWorld->Step(timeStep, velocityIterations, positionIterations);

  physicWorld->ClearForces();
}

void World::AddVehicle(Vehicle* vehicle) { vehicles.push_back(vehicle); }

void World::AddCollectable(Collectable* collectable) {
  collectables.push_back(collectable);
}

void World::AddObstacle(Obstacle* obstacle) { obstacles.push_back(obstacle); }

b2World* World::GetPhysicWorld() const { return physicWorld; }

std::vector<Vehicle*>& World::GetVehicle() { return vehicles; }

std::vector<Collectable*>& World::GetCollectable() { return collectables; }

std::vector<Obstacle*>& World::GetObstacle() { return obstacles; }