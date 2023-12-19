#ifndef INTERVAL_H
#define INTERVAL_H

#include "src/utils/utils.h"

/**
 * @brief This class represents an interval with a minimum and maximum value.
 *
 * An interval is defined by two values, min and max. The class provides methods to check if a value is contained within the interval or if it surrounds a value.
 */
class interval {
public:
    double min, max; // The minimum and maximum values of the interval.

    /**
     * @brief Default constructor. Creates an empty interval.
     */
    interval() : min(+infinity), max(-infinity) {}

    /**
     * @brief Constructor that sets the min and max values of the interval.
     * @param _min The minimum value of the interval.
     * @param _max The maximum value of the interval.
     */
    interval(double _min, double _max) : min(_min), max(_max) {}

    /**
     * @brief Checks if a value is contained within the interval.
     * @param x The value to check.
     * @return True if the value is within the interval, false otherwise.
     */
    bool contains(double x) const {
        return min <= x && x <= max;
    }

    /**
     * @brief Checks if a value is surrounded by the interval.
     * @param x The value to check.
     * @return True if the value is strictly within the interval, false otherwise.
     */
    bool surrounds(double x) const {
        return min < x && x < max;
    }

    /**
    * @brief Clamps a value within the interval.
    *
    * This method checks if a given value is less than the minimum or greater than the maximum of the interval.
    * If the value is less than the minimum, it returns the minimum.
    * If the value is greater than the maximum, it returns the maximum.
    * Otherwise, it returns the original value.
    *
    * @param x The value to clamp.
    * @return The clamped value.
    */
    double clamp(double x) const {
        if (x < min) return min;
        if (x > max) return max;
        return x;
    }

    static const interval empty, universe; // Static instances representing an empty and a universal interval.
};

/**
 * @brief Static instance representing an empty interval.
 */
const static interval empty (+infinity, -infinity);

/**
 * @brief Static instance representing a universal interval.
 */
const static interval universe (-infinity, +infinity);

#endif