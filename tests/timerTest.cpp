#include <gtest/gtest.h>

#include <timer.hpp>

// Test fixture for Timer class
struct Tests : public ::testing::Test {
  Timer* timer;
  virtual void SetUp() override {
    // Set up a timer instance
    timer = new Timer(2);
  }

  // Tear down the test fixture
  virtual void TearDown() override { delete timer; }
};

// Test Tick() function
TEST_F(Tests, timerTest) {
  // Check if after 2 ticks the timer should return true
  EXPECT_FALSE(timer->Tick());
  EXPECT_TRUE(timer->Tick());
}