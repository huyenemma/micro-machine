#ifndef NEGATIVE_BUFF_HPP
#define NEGATIVE_BUFF_HPP

#include <string>

#include "buff.hpp"
#include "vehicle.hpp"

namespace NegativeBuff {

/**
 * @class ReverseMushroom
 * @brief A class representing a reverse mushroom negative buff.
 */
class ReverseMushroom : public Buff {
 private:
  float buffIntensity;     ///< Intensity of the reverse effect.
  std::string imagePath_;  ///< Path to the image associated with the buff.

 public:
  /**
   * @brief Constructor for ReverseMushroom.
   * @param duration The duration of the buff effect.
   * @param intensity The intensity of the reverse effect.
   */
  ReverseMushroom(int duration, float intensity);

  /**
   * @brief Applies the reverse effect on a Vehicle.
   * @param vehicle The Vehicle on which the effect is applied.
   */
  void ApplyEffect(Vehicle* vehicle) override;

  /**
   * @brief Reverses the effect on a Vehicle.
   * @param vehicle The Vehicle on which the effect is reversed.
   */
  void ReverseEffect(Vehicle* vehicle) override;

  /**
   * @brief Destructor for ReverseMushroom.
   */
  ~ReverseMushroom() override;
};

/**
 * @class CrazyRotate
 * @brief A class representing a crazy rotate negative buff.
 */
class CrazyRotate : public Buff {
 private:
  float degree_;     ///< Intensity of the rotation effect.
  float intensity_;  ///< Torque applied during rotation.

 public:
  /**
   * @brief Constructor for CrazyRotate.
   * @param id The identifier for the buff.
   * @param duration The duration of the buff effect.
   * @param torque The torque applied during rotation.
   * @param intensity The intensity of the rotation effect.
   */
  CrazyRotate(int duration, float degree, float intensity);

  /**
   * @brief Applies the rotation effect on a Vehicle.
   * @param vehicle The Vehicle on which the effect is applied.
   */
  void ApplyEffect(Vehicle* vehicle) override;

  /**
   * @brief Reverses the rotation effect on a Vehicle.
   * @param vehicle The Vehicle on which the effect is reversed.
   */
  void ReverseEffect(Vehicle* vehicle) override;

  /**
   * @brief Destructor for CrazyRotate.
   */
  ~CrazyRotate() override;
};

}  // namespace NegativeBuff

#endif  // NEGATIVE_BUFF_HPP
