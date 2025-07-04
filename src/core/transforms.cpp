/** @file Source file for common reference frame transformations */

#include "plant/core/transforms.hpp"

namespace plant {
namespace core {
namespace transforms {

float dot_v3f(types::Vector3f u, types::Vector3f v) {
    return u.x * v.x + u.y * v.y + u.z * v.z;
}

types::Vector3f cross_v3f(types::Vector3f u, types::Vector3f v) {
    types::Vector3f w = {u.y * v.z - u.z * v.y, u.z * v.x - u.x * v.z,
                         u.x * v.y - u.y * v.x};

    return w;
}

}  // namespace transforms
}  // namespace core
}  // namespace plant
