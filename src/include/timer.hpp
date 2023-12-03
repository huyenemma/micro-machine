#ifndef TIMER_HPP
#define TIMER_HPP

#include <iostream>
#include <string>

/**
 * @class Timer
 * @brief Represents a simple countdown timer.
 */
class Timer {
 private:
  int timeLeft;  ///< The time remaining on the timer.

 public:
  /**
   * @brief Constructor for Timer.
   * @param timeLeft The initial time left on the timer.
   */
  Timer(int timeLeft);

  /**
   * @brief Destructor for Timer.
   */
  virtual ~Timer(){};

  /**
   * @brief Decreases the time remaining on the timer by one tick.
   * @return True if the object should be removed, false otherwise.
   */
  bool Tick();
};

#endif  // TIMER_HPP
