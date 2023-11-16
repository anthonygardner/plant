/** @file Header file for IMU sensor */

#pragma once

#include "../core/structs.h"

namespace plant {
namespace sensors {

class IMU {
 public:
   float wx;
   float wy;

  IMU() : wx(0.0), wy(0.0) {};
  IMU(float wx, float wy) : wx(wx), wy(wy) {};

  ~IMU() {};
};

} // namespace sensors
} // namespace plant
