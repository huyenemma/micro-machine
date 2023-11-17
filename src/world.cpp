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
}

void World::AddVehicle(Vehicle* vehicle) { vehicles.push_back(vehicle); }

b2World* World::GetPhysicWorld() const { return physicWorld; }

std::vector<Vehicle*>& World::GetVehicle() { return vehicles; }

void World::AddObstacle(Obstacle* obstacle) { obstacles.push_back(obstacle); }

std::vector<Obstacle*>& World::GetObstacle() { return obstacles; }