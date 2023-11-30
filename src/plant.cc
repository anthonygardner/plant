/** @file Source file for generating Python API with pybind11 */

#include <string>

#include <pybind11/pybind11.h>

#include "./core/transforms.h"
#include "./core/types.h"
#include "./sensors/imu.h"

namespace py = pybind11;

PYBIND11_MODULE(_plant, m) {
  // create the "types" module and overload operators
  auto m_types = m.def_submodule("types");

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

  py::enum_<plant::core::types::AltType>(m_types, "AltType")
    .value("HeightAboveGeoid", plant::core::types::AltType::HeightAboveGeoid)
    .value("HeightAboveEllipsoid", plant::core::types::AltType::HeightAboveEllipsoid)
    .value("MeanSeaLevel", plant::core::types::AltType::MeanSeaLevel);

  py::class_<plant::core::types::LatLonAlt>(m_types, "LatLonAlt")
    .def(py::init<>())
    .def(py::init<float, float, float, plant::core::types::AltType>(), py::arg("lat"), py::arg("lon"), py::arg("alt"), py::arg("alt_type"))
    .def_readwrite("lat", &plant::core::types::LatLonAlt::lat)
    .def_readwrite("lon", &plant::core::types::LatLonAlt::lon)
    .def_readwrite("alt", &plant::core::types::LatLonAlt::alt)
    .def_readwrite("alt_type", &plant::core::types::LatLonAlt::alt_type);

  py::class_<plant::core::types::CartPos>(m_types, "CartPos")
    .def(py::init<>());

  py::class_<plant::core::types::CartVel>(m_types, "CartVel")
    .def(py::init<>());

  py::class_<plant::core::types::CartAcc>(m_types, "CartAcc")
    .def(py::init<>());

  py::class_<plant::core::types::AttRpy>(m_types, "AttRpy")
    .def(py::init<>());

  py::class_<plant::core::types::AttQuat>(m_types, "AttQuat")
    .def(py::init<>());

  py::class_<plant::core::types::State>(m_types, "State")
    .def(py::init<>());

  // create the "transforms" module and add methods to it
  auto m_transforms = m.def_submodule("transforms");

  m_transforms.def("dot_v3f", &plant::core::transforms::dot_v3f);
  m_transforms.def("cross_v3f", &plant::core::transforms::cross_v3f);

  // create the "sensors" module and add the imu to it
  auto m_sensors = m.def_submodule("sensors");

  py::class_<plant::sensors::IMU>(m_sensors, "IMU")
    .def(py::init<>())
    .def(py::init<float, float>(), py::arg("wx"), py::arg("wy"))
    .def_readwrite("wx", &plant::sensors::IMU::wx)
    .def_readwrite("wy", &plant::sensors::IMU::wy)
    .def("__repr__", [](const plant::sensors::IMU &imu) {
      return "[" + std::to_string(imu.wx) + ", " + std::to_string(imu.wy) + "]";
    }, py::is_operator());
}
