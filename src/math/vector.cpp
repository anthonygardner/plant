#include <plant/math/vector.hpp>

#include <cmath>
#include <stdexcept>

namespace plant::math {

Vector Vector::normalize() const {
    auto magnitude = x * x + y * y + z * z;

    Vector norm = Vector(
        x / magnitude,
        y / magnitude,
        z / magnitude
    );

    return norm;
}

}  // namespace plant::math
