#include <gtest/gtest.h>

#include <vehicle.hpp>

// Test fixture for Vehicle class
class VehicleTest : public ::testing::Test {
 protected:
  b2World* world;
  virtual void SetUp() {
    world = new b2World(b2Vec2(0, 0));  // Create a Box2D world
  }

  // Tear down the test fixture
  virtual void TearDown() { delete world; }
};

// Test the GetPosition function
TEST_F(VehicleTest, GetPosition) {
  sf::Texture texture;

  Vehicle vehicle(world, 0, 0, texture);  // Create a Vehicle instance
  auto position = vehicle.GetPosition();

  // Check if the initial position is (0, 0)
  EXPECT_FLOAT_EQ(position.first, 0.0f);
  EXPECT_FLOAT_EQ(position.second, 0.0f);
}

// Test the ToggleForce function
TEST_F(VehicleTest, ToggleForce) {
  sf::Texture texture;

  Vehicle vehicle(world, 0, 0, texture);  // Create a Vehicle instance
  vehicle.ToggleForce(true);

  // Check if the force is turned on
  EXPECT_TRUE(vehicle.GetForce());
}
