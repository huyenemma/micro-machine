/**
 * @file CheckPoint.h
 * @brief Header file for CheckPoint and StartLine classes.
 *
 * This file contains the definitions of CheckPoint and StartLine classes,
 * which are used to define checkpoints and start lines in game environment.
 */

#ifndef CHECKPOINT_H
#define CHECKPOINT_H

#include <SFML/Graphics.hpp>
#include <algorithm>
#include <iostream>
#include <utility>

#include "box2dInclude.hpp"
#include "outsideArea.hpp"
#include "userDataPointer.hpp"
#include "vehicle.hpp"

/**
 * @class CheckPoint
 * @brief Represents a checkpoint in the game world.
 *
 * The CheckPoint class is used to create checkpoints in the game world.
 * Vehicle need to visit all hidden checkpoints to consider as finishing one round
 */
class CheckPoint : public OutsideArea {
 public:
    /**
     * @brief Constructor for CheckPoint.
     * @param world The Box2D world where the checkpoint will exist.
     * @param position The position of the checkpoint in the world.
     * @param height The height of the checkpoint area.
     * @param width The width of the checkpoint area.
     */
    CheckPoint(b2World* world, b2Vec2 position, float height, float width);

    /**
     * @brief Handle the event when a vehicle contacts the checkpoint.
     * @param car A pointer to the vehicle that made contact with the checkpoint.
     */
    virtual void OnContact(Vehicle* car) override;

    /**
     * @brief Check if a vehicle has visited this checkpoint.
     * @param car A pointer to the vehicle to check.
     * @return True if the vehicle has visited, false otherwise.
     */
    bool IsVisitedBy(Vehicle* car) const;

    /**
     * @brief Remove a vehicle from the list of those who have visited this checkpoint.
     * @param car A pointer to the vehicle to be removed.
     */
    void RemoveVisitedCar(Vehicle* car);

private:
    std::vector<Vehicle*> visitedVehicles_; ///< List of vehicles that have visited this checkpoint.

    /**
     * @brief Add a vehicle to the list of those who have visited this checkpoint.
     * @param car A pointer to the vehicle to be added.
     */
    void AddVisitedCar(Vehicle* car);
};

/**
 * @class StartLine
 * @brief Represents the starting line and manages checkpoints in the game.
 *
 * The StartLine class extends CheckPoint and adds functionality to manage
 * multiple checkpoints in the game, tracking the progress of vehicles through these checkpoints.
 */
class StartLine : public CheckPoint {
 public:
    /**
     * @brief Constructor for StartLine.
     * @param world The Box2D world where the start line will exist.
     * @param position The position of the start line in the world.
     * @param height The height of the start line area.
     * @param width The width of the start line area.
     */
    StartLine(b2World* world, b2Vec2 position, float height, float width);

    /**
     * @brief Handle the event when a vehicle contacts the start line.
     * @param car A pointer to the vehicle that made contact with the start line.
     */
    virtual void OnContact(Vehicle* car) override;

    /**
     * @brief Add a checkpoint to be managed by this start line.
     * @param checkpoint A pointer to the checkpoint to be added.
     */
    void AddCheckPoint(CheckPoint* checkpoint);

    /**
     * @brief Destructor for StartLine.
     */
    ~StartLine();

    /**
     * @brief Get the points of each vehicle based on checkpoints visited.
     * @return A map of vehicles to their respective points.
     */
    std::map<Vehicle*,int> GetPoints();

private:
    std::vector<CheckPoint*> CheckPoints_; ///< List of checkpoints managed by this start line.
    std::map<Vehicle*,int> points; ///< Points of each vehicle based on checkpoints visited.
};

#endif // CHECKPOINT_H
