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

    virtual void OnContact(Vehicle* car) override;

    bool IsVisitedBy(Vehicle* car) const;

    void RemoveVisitedCar(Vehicle* car);

private:
    std::vector<Vehicle*> visitedVehicles_;

    void AddVisitedCar(Vehicle* car);
};

class StartLine : public CheckPoint {
public:
    StartLine(b2World* world, b2Vec2 position, float height, float width);

    virtual void OnContact(Vehicle* car) override;

    void AddCheckPoint(CheckPoint* checkpoint);

    ~StartLine();

    std::map<Vehicle*,int> GetPoints();

private:
    std::vector<CheckPoint*> CheckPoints_;
    std::map<Vehicle*,int> points;
};


#endif

