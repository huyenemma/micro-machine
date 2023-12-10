#ifndef REAL_TIME_HPP
#define REAL_TIME_HPP

#include <SFML/Graphics.hpp>
#include <chrono>
#include <iomanip>
#include <sstream>

constexpr int CHAR_SIZE = 30;  ///< Default character size for the time display.

/**
 * @class RealTime
 * @brief A class representing a real-time countdown timer.
 */
class RealTime {
 private:
  int duration_;  ///< The duration of the countdown timer.
  std::chrono::steady_clock::time_point
      startTime_;      ///< The start time of the countdown.
  sf::Text timeText_;  ///< The text object for displaying the time.
  sf::Text player1RoundsText_;  ///< The text object for displaying the number of rounds of player 1.
  sf::Text player2RoundsText_;  ///< The text object for displaying the number of rounds of player 2.
  int gameMode; // 1 for one player, 2 for two players

 public:
  /**
   * @brief Constructor for RealTime.
   * @param duration The duration of the countdown timer.
   * @param font The font used for rendering the time text.
   * @param color The color of the time text (default is sf::Color::White).
   * @param position The position of the time text (default is sf::Vector2f(10,
   * 10)).
   */
  RealTime(int duration, const sf::Font& font,
           sf::Color color = sf::Color::White,
           sf::Vector2f position = sf::Vector2f(10, 10));

  /**
   * @brief Sets up the initial state of the countdown timer.
   */
  void SetUp();

  /**
   * @brief Checks if the time has run out.
   * @return True if the time is up, false otherwise.
   */
  bool IsTimeUp();

  /**
   * @brief Updates the countdown timer.
   */
  void Update(int player1Rounds, int player2Rounds);

  void SetGameMode(int mode);
  
  void SetPlayerRounds(int player1Rounds, int player2Rounds);

  /**
   * @brief Draws the countdown timer on the provided SFML window.
   * @param window The SFML window on which to draw the countdown timer.
   */
  void Draw(sf::RenderWindow& window);
};

#endif  // REAL_TIME_HPP
