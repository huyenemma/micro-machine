#include "./include/realTime.hpp"

RealTime::RealTime(int duration, const sf::Font& font, sf::Color color, sf::Vector2f position)
    : duration_(duration), gameMode(1) {

  timeText_.setFont(font);
  timeText_.setCharacterSize(CHAR_SIZE);
  timeText_.setFillColor(sf::Color::White);
  timeText_.setOutlineColor(sf::Color::Black); 
  timeText_.setOutlineThickness(1);
  timeText_.setStyle(sf::Text::Bold); 
  timeText_.setPosition(position);

  player1RoundsText_.setFont(font);
  player1RoundsText_.setCharacterSize(CHAR_SIZE);
  player1RoundsText_.setOutlineColor(sf::Color::Black); 
  player1RoundsText_.setOutlineThickness(1);
  player1RoundsText_.setStyle(sf::Text::Bold); 
  player1RoundsText_.setPosition(position.x - 310, position.y);

  player2RoundsText_.setFont(font);
  player2RoundsText_.setCharacterSize(CHAR_SIZE);
  player2RoundsText_.setOutlineColor(sf::Color::Black); 
  player2RoundsText_.setOutlineThickness(1);
  player2RoundsText_.setStyle(sf::Text::Bold); 
  player2RoundsText_.setPosition(position.x + 270, position.y);

}

void RealTime::SetUp() { startTime_ = std::chrono::steady_clock::now(); }

bool RealTime::IsTimeUp() {
  auto currentTime = std::chrono::steady_clock::now();
  auto elapsedTime = std::chrono::duration_cast<std::chrono::minutes>(
      currentTime - startTime_);
  return (elapsedTime >= std::chrono::minutes(duration_));
}

void RealTime::SetGameMode(int mode) {
    gameMode = mode;
}

void RealTime::SetPlayerRounds(int player1Rounds, int player2Rounds) {
  player1RoundsText_.setString("BUFFALO: " + std::to_string(player1Rounds) + " rounds");
  player2RoundsText_.setString("GOAT: " + std::to_string(player2Rounds) + " rounds");
}

void RealTime::Update(int player1Rounds, int player2Rounds) {
  auto currentTime = std::chrono::steady_clock::now();
  auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(
      currentTime - startTime_);
  int totalSeconds = elapsedTime.count();

  int minutes = totalSeconds / 60;
  int seconds = totalSeconds % 60;

  std::stringstream timeStream;
  timeStream << std::setw(2) << std::setfill('0') << minutes << ":"
             << std::setw(2) << std::setfill('0') << seconds;

  timeText_.setString("Time: " + timeStream.str());
  SetPlayerRounds(player1Rounds, player2Rounds);
}


void RealTime::Draw(sf::RenderWindow& window) {

  sf::RectangleShape backgroundBox;
  backgroundBox.setSize(sf::Vector2f(785, CHAR_SIZE + 10)); 
  backgroundBox.setFillColor(sf::Color(0, 0, 0, 128)); // Semi-transparent black
  backgroundBox.setOutlineColor(sf::Color::Black); 
  backgroundBox.setOutlineThickness(1);
  backgroundBox.setPosition(10, 10); // 5 is padding offset

  window.draw(backgroundBox);
  window.draw(timeText_); 
  window.draw(player1RoundsText_);
  if (gameMode == 2) {
    window.draw(player2RoundsText_); 
  }

}
