
#ifndef BUFF_HPP
#define BUFF_HPP

#include <string>

#include "timer.hpp"

class Vehicle;

/**
 * @brief Enumeration for different types of buff effects.
 */
enum BuffEffect {
  onetime,      ///< Buff effect happens only once.
  continuous,   ///< Buff effect continues over a duration.
};

/**
 * @brief Enumeration for buff types (positive or negative).
 */
enum class BuffType {
  Positive,  ///< Positive buff type.
  Negative   ///< Negative buff type.
};

/**
 * @brief Base class for Buffs, derived from Timer.
 */
class Buff : public Timer {
 protected:
  std::string id;         ///< Unique identifier for the buff.
  BuffType type_;         ///< Type of the buff (Positive or Negative).
  BuffEffect effectType_; ///< Type of the buff effect (onetime or continuous).

 public:
  /**
   * @brief Constructor for Buff class.
   * @param duration The duration of the buff.
   * @param type Type of the buff (Positive or Negative).
   * @param effectType Type of the buff effect (onetime or continuous).
   */
  Buff(int duration, BuffType type, BuffEffect effectType)
      : Timer(duration), type_(type), effectType_(effectType) {}

  /**
   * @brief Destructor for Buff class.
   */
  ~Buff(){};

  /**
   * @brief Applies the buff effect to a Vehicle.
   * @param vehicle The Vehicle to which the buff effect is applied.
   */
  virtual void ApplyEffect(Vehicle* vehicle) = 0;

  /**
   * @brief Reverses the buff effect applied to a Vehicle.
   * @param vehicle The Vehicle to which the buff effect is reversed.
   */
  virtual void ReverseEffect(Vehicle* vehicle) = 0;

  /**
   * @brief Checks if the buff effect is continuous.
   * @return True if the buff effect is continuous, false otherwise.
   */
  bool IsContinuous() { return (effectType_ == BuffEffect::continuous); };

  /**
   * @brief Checks if the buff is a negative buff.
   * @return True if the buff is negative, false otherwise.
   */
  bool IsNegativeBuff() { return (type_ == BuffType::Negative); }
};

#endif

