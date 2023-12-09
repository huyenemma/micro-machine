#include <gtest/gtest.h>

#include <timer.hpp>

// fixture
struct Tests : public ::testing::Test {
  Timer* timer;
  virtual void SetUp() override { timer = new Timer(2); }

  virtual void TearDown() override { delete timer; }
};

TEST_F(Tests, vehicleInitialPosition) {
  EXPECT_FALSE(timer->Tick());
  EXPECT_TRUE(timer->Tick());
}