#ifndef REAL_TIME_HPP
#define REAL_TIME_HPP

#include <SFML/Graphics.hpp>
#include <chrono>
#include <iomanip> 
#include <sstream>

constexpr int CHAR_SIZE = 24; ///< Default character size for the time display.

/**
 * @class RealTime
 * @brief A class representing a real-time countdown timer.
 */
class RealTime {
private:
    int duration_; ///< The duration of the countdown timer.
    std::chrono::steady_clock::time_point startTime_; ///< The start time of the countdown.
    sf::Text timeText_; ///< The text object for displaying the time.

public:
    /**
     * @brief Constructor for RealTime.
     * @param duration The duration of the countdown timer.
     * @param font The font used for rendering the time text.
     * @param color The color of the time text (default is sf::Color::White).
     * @param position The position of the time text (default is sf::Vector2f(10, 10)).
     */
    RealTime(int duration, const sf::Font& font, sf::Color color = sf::Color::White, sf::Vector2f position = sf::Vector2f(10, 10));

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
    void Update();

    /**
     * @brief Draws the countdown timer on the provided SFML window.
     * @param window The SFML window on which to draw the countdown timer.
     */
    void Draw(sf::RenderWindow& window);
};

#endif // REAL_TIME_HPP
