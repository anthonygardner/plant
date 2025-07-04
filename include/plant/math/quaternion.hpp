#pragma once

#include <cmath>
#include <iostream>

namespace plant::math {

class Quaternion {
public:
    float w, x, y, z;

    // Constructors
    Quaternion() : w(0), x(0), y(0), z(0) {}
    Quaternion(float w, float x, float y, float z) : w(w), x(x), y(y), z(z) {}

    // Operator overloads
    Quaternion operator+(const Quaternion& other) const {
        return Quaternion(
            w + other.w,
            x + other.x,
            y + other.y,
            z + other.z
        );
    }

    // Other operations
    Quaternion normalize() const;
    Quaternion toMatrix() const;
};

}  // namespace plant::math
