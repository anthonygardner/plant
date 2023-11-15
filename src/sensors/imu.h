/** @file Header file for IMU sensor */

#pragma once

#include "../core/structs.h"

namespace plant {
namespace sensors {

    class IMU {
    public:
      float wx;
      float wy;

      IMU(float wx_, float wy_);

    private:
      float _wx;
      float _wy;
    };

} // namespace sensors
} // namespace plant
