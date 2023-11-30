/** @file Header file for core data types */

#pragma once

namespace plant {
namespace core {
namespace types {

enum class AltType {
    HeightAboveGeoid,
    HeightAboveEllipsoid,
    MeanSeaLevel
};

enum class ReferenceFrame {
    EarthCenteredInertial,
    EarthCenteredEarthFixed,
    EastNorthUp,
    NorthEastDown,
    Body
};

typedef struct {
    float x;
    float y;
    float z;
} Vector3f;

typedef struct {
    float lat;
    float lon;
    float alt;
    AltType alt_type;
} LatLonAlt;

typedef struct {
    float x;
    float y;
    float z;
    ReferenceFrame rf;
} CartPos;

typedef struct {
    float vx;
    float vy;
    float vz;
    ReferenceFrame rf;
} CartVel;

typedef struct {
    float ax;
    float ay;
    float az;
    ReferenceFrame rf;
} CartAcc;

typedef struct {
    float roll;
    float pitch;
    float yaw;
} AttRpy;

typedef struct {
    float w;
    float x;
    float y;
    float z;
} AttQuat;

typedef struct {
    CartPos p;
    CartVel v;
    CartAcc a;
    LatLonAlt lla;
    AttRpy rpy;
    AttQuat q;
} State;

} // namespace types
} // namespace core
} // namespace plant

// TODO: add ndarray
