#include "./include/world.hpp"

World::World(b2Vec2 gravity) { physicWorld = new b2World(gravity); };



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

void World::SetRacingTrack(StartLine* StartLine) { this->startLine = StartLine;}


std::map<Vehicle*,int> World::GetPoints(){
  if (startLine){
    return startLine->GetPoints();
  }
};
World::~World() {
    // Free the StartLine object
    delete startLine;

    // Free all Vehicle objects in the vehicles vector
    for (Vehicle* vehicle : vehicles) {
        delete vehicle;
    }

    // Free all Collectable objects in the collectables vector
    for (Collectable* collectable : collectables) {
        delete collectable;
    }

    // Free all Obstacle objects in the obstacles vector
    for (Obstacle* obstacle : obstacles) {
        delete obstacle;
    }    
    //Free the startline
    delete startLine;

    // Clear the vectors after deleting the objects
    vehicles.clear();
    collectables.clear();
    obstacles.clear();

    // Delete the physics world
    delete physicWorld;
}
