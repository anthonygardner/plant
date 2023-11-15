/** @file Header file for IMU sensor */

#pragma once

#include "../core/structs.h"

namespace plant {
namespace sensors {

    class IMU {
    public:
      // Vector3f specific_force;
      //
      // IMU(Vector3f angular_velocity, specific_force) {
      //   this->angular_velocity = angular_velocity;
      //   this->specific_force = specific_force;
      // }
      float wx;
      float wy;

      IMU(float wx_, float wy_);

      // float get_wx();
    private:
      float _wx;
      float _wy;
    };

} // namespace sensors
} // namespace plant
