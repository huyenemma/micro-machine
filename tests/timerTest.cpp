#include <gtest/gtest.h>

#include <timer.hpp>

// Test fixture for Timer class
struct Tests : public ::testing::Test {
  Timer* timer;
  virtual void SetUp() override { timer = new Timer(2); }

  virtual void TearDown() override { delete timer; }
};

TEST_F(Tests, timerTest) {
  EXPECT_FALSE(timer->Tick());
  EXPECT_TRUE(timer->Tick());
}