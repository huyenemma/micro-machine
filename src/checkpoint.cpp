#include "checkpoint.hpp"

CheckPoint::CheckPoint(b2World* world, b2Vec2 position, float height, float width)
    : OutsideArea(world, position, height, width) {
}

void CheckPoint::OnContact(Vehicle* car) {
    AddVisitedCar(car);
}

std::map<Vehicle*,int> StartLine::GetPoints(){
    return points;
}

bool CheckPoint::IsVisitedBy(Vehicle* car) const {
    return std::find(visitedVehicles_.begin(), visitedVehicles_.end(), car) != visitedVehicles_.end();
}

void CheckPoint::RemoveVisitedCar(Vehicle* car) {
    auto it = std::remove(visitedVehicles_.begin(), visitedVehicles_.end(), car);
    visitedVehicles_.erase(it, visitedVehicles_.end());
}

void CheckPoint::AddVisitedCar(Vehicle* car) {
    if (!IsVisitedBy(car)) {
        visitedVehicles_.push_back(car);
    }
}

StartLine::StartLine(b2World* world, b2Vec2 position, float height, float width)
    : CheckPoint(world, position, height, width) {
}

void StartLine::OnContact(Vehicle* car) {
    CheckPoint::OnContact(car);
    bool giveOnePoint = true;
    for (CheckPoint* checkpoint : CheckPoints_) {
        if (checkpoint->IsVisitedBy(car)) {
            checkpoint->RemoveVisitedCar(car);
        } else {
            giveOnePoint = false;
        }
    }

     if (giveOnePoint) {
        // Check if the car already has a point entry in the map
        auto it = points.find(car);
        if (it != points.end()) {
            // If the car is already in the map, increment the existing point value
            it->second++;
        } else {
            // If the car is not in the map, create a new entry with the value 1
            points[car] = 1;
        }

        std::cout << points[car] << std::endl;
    }
}

void StartLine::AddCheckPoint(CheckPoint* checkpoint) {
    CheckPoints_.push_back(checkpoint);
}

StartLine::~StartLine() {
    // Free all CheckPoint objects in the CheckPoints_ vector
    for (CheckPoint* checkpoint : CheckPoints_) {
        delete checkpoint;
    }
    // Clear the vector after deleting the objects
    CheckPoints_.clear();
}
