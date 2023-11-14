#pragma once

/** @file Header file for common reference frame transformations */

namespace core {
namespace transforms {

    float dot_v3f(Vector3f u, Vector3f v);
    Vector3f cross_v3f(Vector3f u, Vector3f v);

} // namespace transforms
} // namespace core
