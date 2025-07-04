/** @file Header file for common reference frame transformations */

#pragma once

#include "plant/core/types.hpp"

namespace plant {
namespace core {
namespace transforms {

float dot_v3f(types::Vector3f u, types::Vector3f v);

types::Vector3f cross_v3f(types::Vector3f u, types::Vector3f v);

}  // namespace transforms
}  // namespace core
}  // namespace plant
