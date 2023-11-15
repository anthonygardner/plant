/** @file Source file for IMU sensor */

#include "./imu.h"


plant::sensors::IMU::IMU(float wx_, float wy_)
  : _wx { wx_ }
  , _wy { wy_ }
  {}
