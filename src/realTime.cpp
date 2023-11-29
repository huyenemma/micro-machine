#include "./include/realTime.hpp"

RealTime::RealTime(int duration, const sf::Font& font, sf::Color color, sf::Vector2f position) 
    : duration_(duration) {
    timeText_.setFont(font);
    timeText_.setCharacterSize(CHAR_SIZE);
    timeText_.setFillColor(color);
    timeText_.setPosition(position);
}

void RealTime::SetUp() {
    startTime_ = std::chrono::steady_clock::now();
}

bool RealTime::IsTimeUp() {
    auto currentTime = std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::minutes>(currentTime - startTime_);
    return (elapsedTime >= std::chrono::minutes(duration_));
}

void RealTime::Update() {
    auto currentTime = std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime_);
    int totalSeconds = elapsedTime.count();

    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;

    std::stringstream timeStream;
    timeStream << std::setw(2) << std::setfill('0') << minutes << ":" 
               << std::setw(2) << std::setfill('0') << seconds;

    timeText_.setString("Time: " + timeStream.str());
}

void RealTime::Draw(sf::RenderWindow& window) {
    window.draw(timeText_);
}
