#ifndef CHECKPOINT_H
#define CHECKPOINT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <utility>

#include "box2dInclude.hpp"
#include "userDataPointer.hpp"
#include "vehicle.hpp"
#include "outsideArea.hpp"




#include <algorithm> 

class CheckPoint : public OutsideArea {
public:
    CheckPoint(b2World* world, b2Vec2 position, float height, float width);

    virtual void OnContact(Vehicle* car) override {
        // Add the car to the visitedVehicles if not already present
        AddVisitedCar(car);
    }

    bool IsVisitedBy(Vehicle* car) const {
        // Check if the car is in the visitedVehicles
        return std::find(visitedVehicles_.begin(), visitedVehicles_.end(), car) != visitedVehicles_.end();
    }

    void RemoveVisitedCar(Vehicle* car) {
        // Remove the car from visitedVehicles_ if present
        auto it = std::remove(visitedVehicles_.begin(), visitedVehicles_.end(), car);
        visitedVehicles_.erase(it, visitedVehicles_.end());
    }

private:
    std::vector<Vehicle*> visitedVehicles_;

    void AddVisitedCar(Vehicle* car) {
        // Add the car to the visitedVehicles if not already present
        if (!IsVisitedBy(car)) {
            visitedVehicles_.push_back(car);
        }
    }
};

class StartLine : public CheckPoint {
public:
    StartLine(b2World* world, b2Vec2 position, float height, float width);

    //award one points if the care have visited all check points
    virtual void OnContact(Vehicle* car) override {
        // Call the base class method
        CheckPoint::OnContact(car);
        bool giveOnePoint = true;
        // If other checkpoints contain the car, remove it from those checkpoints
        for (CheckPoint* checkpoint : CheckPoints_) {
            if (checkpoint->IsVisitedBy(car)) {
                checkpoint->RemoveVisitedCar(car);
            } else {
                giveOnePoint = false;
            }
        }
        if (giveOnePoint) {
            // TODO: give player one points 
            std::cout<<"+1 YaY"<<std::endl;
        }
    }

    void AddCheckPoint(CheckPoint* checkpoint) {
        // Add a checkpoint to the list
        CheckPoints_.push_back(checkpoint);
    }

private:
    std::vector<CheckPoint*> CheckPoints_;
};


#endif

