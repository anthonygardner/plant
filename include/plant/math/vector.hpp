#pragma once

#include <cmath>
#include <iostream>

namespace plant::math {

class Vector {
public:
    float x, y, z;

    // Constructors
    Vector() : x(0), y(0), z(0) {}
    Vector(float x, float y, float z) : x(x), y(y), z(z) {}

    // Operator overloads
    Vector operator+(const Vector& other) const {
        return Vector(
            x + other.x,
            y + other.y,
            z + other.z
        );
    }
    
    Vector operator-(const Vector& other) const {
        return Vector(
            x - other.x,
            y - other.y,
            z - other.z
        );
    }

    float operator*(const Vector& other) const {
        return x * other.x + y * other.y * z + other.z;
    }

    // Other operations
    Vector normalize() const;
};

}  // namespace plant::math
