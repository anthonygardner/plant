/** @file Source file for generating Python API with pybind11 */

#include <string>

#include <pybind11/pybind11.h>

#include "./core/transforms.h"
#include "./core/types.h"
#include "./sensors/imu.h"

namespace py = pybind11;

PYBIND11_MODULE(_plant, m) {
  //====================================================================================================
  // create the "types" module and add data types to it

  auto m_types = m.def_submodule("types");

  //----------------------------------------------------------------------------------------------------
  // enums

  py::enum_<plant::core::types::AltType>(m_types, "AltType")
    .value("HeightAboveGeoid", plant::core::types::AltType::HeightAboveGeoid)
    .value("HeightAboveEllipsoid", plant::core::types::AltType::HeightAboveEllipsoid)
    .value("MeanSeaLevel", plant::core::types::AltType::MeanSeaLevel);

  py::enum_<plant::core::types::ReferenceFrame>(m_types, "ReferenceFrame")
    .value("EarthCenteredInertial", plant::core::types::ReferenceFrame::EarthCenteredInertial)
    .value("EarthCenteredEarthFixed", plant::core::types::ReferenceFrame::EarthCenteredEarthFixed)
    .value("EastNorthUp", plant::core::types::ReferenceFrame::EastNorthUp)
    .value("NorthEastDown", plant::core::types::ReferenceFrame::NorthEastDown)
    .value("Body", plant::core::types::ReferenceFrame::Body);

  //----------------------------------------------------------------------------------------------------
  // classes

  py::class_<plant::core::types::Vector3f>(m_types, "Vector3f")
    .def(py::init<float, float, float>())
    .def_readwrite("x", &plant::core::types::Vector3f::x)
    .def_readwrite("y", &plant::core::types::Vector3f::y)
    .def_readwrite("z", &plant::core::types::Vector3f::z)
    .def("__add__", [](const plant::core::types::Vector3f &u, plant::core::types::Vector3f v) {
      plant::core::types::Vector3f w = {
        u.x + v.x,
        u.y + v.y,
        u.z + v.z
      };
      return w;
    }, py::is_operator())
    .def("__sub__", [](const plant::core::types::Vector3f &u, plant::core::types::Vector3f v) {
      plant::core::types::Vector3f w = {
        u.x - v.x,
        u.y - v.y,
        u.z - v.z
      };
      return w;
    }, py::is_operator());

  py::class_<plant::core::types::LatLonAlt>(m_types, "LatLonAlt")
    .def(py::init<>())
    .def(py::init<float, float, float, plant::core::types::AltType>(), py::arg("lat"), py::arg("lon"), py::arg("alt"), py::arg("alt_type"))
    .def_readwrite("lat", &plant::core::types::LatLonAlt::lat)
    .def_readwrite("lon", &plant::core::types::LatLonAlt::lon)
    .def_readwrite("alt", &plant::core::types::LatLonAlt::alt)
    .def_readwrite("alt_type", &plant::core::types::LatLonAlt::alt_type);

  py::class_<plant::core::types::CartPos>(m_types, "CartPos")
    .def(py::init<>())
    .def(py::init<float, float, float, plant::core::types::ReferenceFrame>(), py::arg("x"), py::arg("y"), py::arg("z"), py::arg("rf"))
    .def_readwrite("x", &plant::core::types::CartPos::x)
    .def_readwrite("y", &plant::core::types::CartPos::y)
    .def_readwrite("z", &plant::core::types::CartPos::z)
    .def_readwrite("rf", &plant::core::types::CartPos::rf);

  py::class_<plant::core::types::CartVel>(m_types, "CartVel")
    .def(py::init<>())
    .def(py::init<float, float, float, plant::core::types::ReferenceFrame>(), py::arg("vx"), py::arg("vy"), py::arg("vz"), py::arg("rf"))
    .def_readwrite("vx", &plant::core::types::CartVel::vx)
    .def_readwrite("vy", &plant::core::types::CartVel::vy)
    .def_readwrite("vz", &plant::core::types::CartVel::vz)
    .def_readwrite("rf", &plant::core::types::CartVel::rf);

  py::class_<plant::core::types::CartAcc>(m_types, "CartAcc")
    .def(py::init<>())
    .def(py::init<float, float, float, plant::core::types::ReferenceFrame>(), py::arg("ax"), py::arg("ay"), py::arg("az"), py::arg("rf"))
    .def_readwrite("ax", &plant::core::types::CartAcc::ax)
    .def_readwrite("ay", &plant::core::types::CartAcc::ay)
    .def_readwrite("az", &plant::core::types::CartAcc::az)
    .def_readwrite("rf", &plant::core::types::CartAcc::rf);

  py::class_<plant::core::types::AttRpy>(m_types, "AttRpy")
    .def(py::init<>())
    .def(py::init<float, float, float>(), py::arg("roll"), py::arg("pitch"), py::arg("yaw"))
    .def_readwrite("roll", &plant::core::types::AttRpy::roll)
    .def_readwrite("pitch", &plant::core::types::AttRpy::pitch)
    .def_readwrite("yaw", &plant::core::types::AttRpy::yaw);

  py::class_<plant::core::types::AttQuat>(m_types, "AttQuat")
    .def(py::init<>())
    .def(py::init<float, float, float, float>(), py::arg("w"), py::arg("x"), py::arg("y"), py::arg("z"))
    .def_readwrite("w", &plant::core::types::AttQuat::w)
    .def_readwrite("x", &plant::core::types::AttQuat::x)
    .def_readwrite("y", &plant::core::types::AttQuat::y)
    .def_readwrite("z", &plant::core::types::AttQuat::z);

  py::class_<plant::core::types::State>(m_types, "State")
    .def(py::init<>())
    .def(py::init<plant::core::types::CartPos, plant::core::types::CartVel, plant::core::types::CartAcc, plant::core::types::LatLonAlt, plant::core::types::AttRpy, plant::core::types::AttQuat>(), py::arg("p"), py::arg("v"), py::arg("a"), py::arg("lla"), py::arg("rpy"), py::arg("q"))
    .def_readwrite("p", &plant::core::types::State::p)
    .def_readwrite("v", &plant::core::types::State::v)
    .def_readwrite("a", &plant::core::types::State::a)
    .def_readwrite("lla", &plant::core::types::State::lla)
    .def_readwrite("rpy", &plant::core::types::State::rpy)
    .def_readwrite("q", &plant::core::types::State::q);

  //====================================================================================================
  // create the "transforms" module and add methods to it

  auto m_transforms = m.def_submodule("transforms");

  //----------------------------------------------------------------------------------------------------
  // methods

  // m_transforms.def("dot_v3f", &plant::core::transforms::dot_v3f);
  // m_transforms.def("cross_v3f", &plant::core::transforms::cross_v3f);

  //====================================================================================================
  // create the "sensors" module and add the imu to it

  auto m_sensors = m.def_submodule("sensors");

  //----------------------------------------------------------------------------------------------------
  // classes

  py::class_<plant::sensors::IMU>(m_sensors, "IMU")
    .def(py::init<>())
    .def(py::init<float, float>(), py::arg("wx"), py::arg("wy"))
    .def_readwrite("wx", &plant::sensors::IMU::wx)
    .def_readwrite("wy", &plant::sensors::IMU::wy)
    .def("__repr__", [](const plant::sensors::IMU &imu) {
      return "[" + std::to_string(imu.wx) + ", " + std::to_string(imu.wy) + "]";
    }, py::is_operator());
}
