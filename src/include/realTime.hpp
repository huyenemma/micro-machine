#ifndef REAL_TIME_HPP
#define REAL_TIME_HPP

#include <SFML/Graphics.hpp>
#include <chrono>
#include <iomanip> 
#include <sstream>

constexpr int CHAR_SIZE = 24; 

class RealTime {
private: 
    int duration_;
    std::chrono::steady_clock::time_point startTime_;
    sf::Text timeText_;

public:
    RealTime(int duration, const sf::Font& font, sf::Color color = sf::Color::White, sf::Vector2f position = sf::Vector2f(10, 10));

    void SetUp();
    bool IsTimeUp();
    void Update();
    void Draw(sf::RenderWindow& window);
};

#endif // REAL_TIME_HPP
