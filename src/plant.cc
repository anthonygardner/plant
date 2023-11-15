/** @file Source file for generating Python API with pybind11 */

#include <pybind11/pybind11.h>

#include "./core/structs.h"
#include "./core/transforms.h"
#include "./sensors/imu.h"

namespace py = pybind11;

PYBIND11_MODULE(_plant, m) {
  // create the "structs" module and overload operators
  auto m_structs = m.def_submodule("structs");

  py::class_<plant::core::Vector3f>(m_structs, "Vector3f")
    .def(py::init<float, float, float>())
    .def_readwrite("x", &plant::core::Vector3f::x)
    .def_readwrite("y", &plant::core::Vector3f::y)
    .def_readwrite("z", &plant::core::Vector3f::z)
    .def("__add__", [](const plant::core::Vector3f &u, plant::core::Vector3f v) {
      plant::core::Vector3f w = {
        u.x + v.x,
        u.y + v.y,
        u.z + v.z
      };
      return w;
    }, py::is_operator())
    .def("__sub__", [](const plant::core::Vector3f &u, plant::core::Vector3f v) {
      plant::core::Vector3f w = {
        u.x - v.x,
        u.y - v.y,
        u.z - v.z
      };
      return w;
    }, py::is_operator());

  // create the "transforms" module and add methods to it
  auto m_transforms = m.def_submodule("transforms");
  m_transforms.def("dot_v3f", &plant::core::transforms::dot_v3f);
  m_transforms.def("cross_v3f", &plant::core::transforms::cross_v3f);

  // create the "sensors" module and add the imu to it
  auto m_sensors = m.def_submodule("sensors");

  py::class_<plant::sensors::IMU>(m_sensors, "IMU")
    .def(py::init<float, float>())
    .def_readwrite("wx", &plant::sensors::IMU::wx)
    .def_readwrite("wy", &plant::sensors::IMU::wy);
}
