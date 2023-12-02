#ifndef POSITIVE_BUFF_HPP
#define POSITIVE_BUFF_HPP

#include <string>
#include "Buff.hpp"
#include "Vehicle.hpp"

namespace PositiveBuff {

    /**
     * @class OxSuperSkillBuff
     * @brief A class representing an Ox super skill positive buff.
     */
    class OxSuperSkillBuff : public Buff {
    private:
        float buffIntensity; ///< Intensity of the super skill effect.

    public:
        /**
         * @brief Constructor for OxSuperSkillBuff.
         * @param duration The duration of the buff effect.
         * @param intensity The intensity of the super skill effect.
         */
        OxSuperSkillBuff(int duration, float intensity);

        /**
         * @brief Applies the super skill effect on a Vehicle.
         * @param vehicle The Vehicle on which the effect is applied.
         */
        void ApplyEffect(Vehicle* vehicle);

        /**
         * @brief Reverses the super skill effect on a Vehicle.
         * @param vehicle The Vehicle on which the effect is reversed.
         */
        void ReverseEffect(Vehicle* vehicle);

        /**
         * @brief Destructor for OxSuperSkillBuff.
         */
        ~OxSuperSkillBuff();
    };

    /**
     * @class MaxSpeed
     * @brief A class representing a maximum speed positive buff.
     */
    class MaxSpeed : public Buff {
    private:
        float boost_; ///< Boost applied to the maximum speed.

    public:
        /**
         * @brief Constructor for MaxSpeed.
         * @param duration The duration of the buff effect.
         * @param boost The boost applied to the maximum speed.
         */
        MaxSpeed(int duration, float boost);

        /**
         * @brief Applies the maximum speed effect on a Vehicle.
         * @param vehicle The Vehicle on which the effect is applied.
         */
        void ApplyEffect(Vehicle* vehicle);

        /**
         * @brief Reverses the maximum speed effect on a Vehicle.
         * @param vehicle The Vehicle on which the effect is reversed.
         */
        void ReverseEffect(Vehicle* vehicle);

        /**
         * @brief Destructor for MaxSpeed.
         */
        ~MaxSpeed();
    };

    /**
     * @class Magnetic
     * @brief A class representing a magnetic positive buff.
     */
    class Magnetic : public Buff {
    private:
        float radius_; ///< Radius of the magnetic effect.

    public:
        /**
         * @brief Constructor for Magnetic.
         * @param duration The duration of the buff effect.
         * @param radius The radius of the magnetic effect.
         */
        Magnetic(int duration, float radius);

        /**
         * @brief Applies the magnetic effect on a Vehicle.
         * @param vehicle The Vehicle on which the effect is applied.
         */
        void ApplyEffect(Vehicle* vehicle);

        /**
         * @brief Reverses the magnetic effect on a Vehicle.
         * @param vehicle The Vehicle on which the effect is reversed.
         */
        void ReverseEffect(Vehicle* vehicle);

        /**
         * @brief Destructor for Magnetic.
         */
        ~Magnetic();
    };

} // namespace PositiveBuff

#endif // POSITIVE_BUFF_HPP
