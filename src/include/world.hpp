/**
 * @file World.hpp
 * @brief Header for the World class.
 *
 * This file contains the definition of the World class, which is used to manage the physics world of the game, including vehicles, collectables, obstacles, and the racing track.
 */

#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "box2dInclude.hpp"
#include "collectable.hpp"
#include "constant.hpp"
#include "obstacle.hpp"
#include "vehicle.hpp"
#include "checkpoint.hpp"

/**
 * @class World
 * @brief Manages the physics world and game entities like vehicles, collectables, and obstacles.
 *
 * The World class is responsible for updating the physics world, keeping track of game entities, and determining the winner of the game.
 */
class World {
 private:
  b2World* physicWorld; ///< Pointer to the Box2D physics world.
  StartLine* startLine; ///< Start line of the racing track.
  std::vector<Vehicle*> vehicles; ///< List of vehicles in the world.
  std::vector<Collectable*> collectables; ///< List of collectables in the world.
  std::vector<Obstacle*> obstacles; ///< List of obstacles in the world.
  Vehicle* winner; ///< Pointer to the winning vehicle.
  
 public:
  /**
   * @brief Constructs a World object with a given gravity.
   *
   * @param gravity The gravitational force applied in the world.
   */
  World(b2Vec2 gravity);

  /**
   * @brief Destructor for World class.
   */
  ~World();

  /**
   * @brief Updates the physics world over a given timestep.
   *
   * @param timeStep The timestep over which the world is updated.
   * @param velocityIterations The number of velocity iterations for the physics calculations.
   * @param positionIterations The number of position iterations for the physics calculations.
   */
  void Update(float timeStep, int velocityIterations, int positionIterations);

  /**
   * @brief Retrieves the winning vehicle.
   *
   * @return Pointer to the winning vehicle.
   */
  Vehicle* GetWinner();

  /**
   * @brief Adds a vehicle to the world.
   *
   * @param vehicle Pointer to the vehicle to be added.
   */
  void AddVehicle(Vehicle* vehicle);

  /**
   * @brief Adds a collectable to the world.
   *
   * @param collectable Pointer to the collectable to be added.
   */
  void AddCollectable(Collectable* collectable);

  /**
   * @brief Sets the racing track for the world.
   *
   * @param startLine Pointer to the start line of the racing track.
   */
  void SetRacingTrack(StartLine* startLine);

  /**
   * @brief Adds an obstacle to the world.
   *
   * @param obstacle Pointer to the obstacle to be added.
   */
  void AddObstacle(Obstacle* obstacle);

  /**
   * @brief Retrieves the points scored by each vehicle.
   *
   * @return Map of vehicles and their corresponding points.
   */
  std::map<Vehicle*,int> GetPoints();

  /**
   * @brief Gets the points scored by a specific vehicle.
   *
   * @param car Pointer to the vehicle.
   * @return The points scored by the vehicle.
   */
  int GetPoint(Vehicle* car);

  /**
   * @brief Checks if any vehicle has won the game.
   *
   * @return True if there is a winner, false otherwise.
   */
  bool HaveAnyOneWin();
  
  /**
   * @brief Gets the physics world.
   *
   * @return Pointer to the Box2D physics world.
   */
  b2World* GetPhysicWorld() const;

  /**
   * @brief Gets the list of vehicles in the world.
   *
   * @return Reference to the vector of vehicles.
   */
  std::vector<Vehicle*>& GetVehicle();

  /**
   * @brief Gets the list of collectables in the world.
   *
   * @return Reference to the vector of collectables.
   */
  std::vector<Collectable*>& GetCollectable();

  /**
   * @brief Gets the list of obstacles in the world.
   *
   * @return Reference to the vector of obstacles.
   */
  std::vector<Obstacle*>& GetObstacle();
  
};

#endif  // WORLD_H
