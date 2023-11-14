/** @file Source file for common reference frame transformations */

#include "structs.h"
#include "transforms.h"

namespace core {
namespace transforms {

    float dot_v3f(Vector3f u, Vector3f v) {
      return u.x * v.x + u.y * v.y + u.z * v.z;
    }

    Vector3f cross_v3f(Vector3f u, Vector3f v) {
        Vector3f w = {
            u.y * v.z - u.z * v.y,
            u.z * v.x - u.x * v.z,
            u.x * v.y - u.y * v.x
        };

        return w;
    }

} // namespace transforms
} // namespace core
