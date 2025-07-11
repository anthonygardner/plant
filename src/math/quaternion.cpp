#include <cmath>
#include <stdexcept>

#include "plant/math/quaternion.hpp"

namespace plant::math {

Quaternion Quaternion::normalize() const {
    Quaternion q;
    return q;
}
Matrix<3, 3> Quaternion::to_matrix() const {
    Matrix<3, 3> m;
    return m;
}

}  // namespace plant::math
