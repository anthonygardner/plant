#include <pybind11/pybind11.h>

#include "./structs.h"
#include "./transforms.h"

namespace py = pybind11;

PYBIND11_MODULE(core, m) {
  // create the "structs" module and overload operators
  auto m_structs = m.def_submodule("structs");

  py::class_<Vector3f>(m, "Vector3f")
    .def(py::init<float, float, float>())
    .def_readwrite("x", &Vector3f::x)
    .def_readwrite("y", &Vector3f::y)
    .def_readwrite("z", &Vector3f::z)
    .def("__add__", [](const Vector3f &u, Vector3f v) {
      Vector3f w = {
        u.x + v.x,
        u.y + v.y,
        u.z + v.z
      };
      return w;
    }, py::is_operator())
    .def("__sub__", [](const Vector3f &u, Vector3f v) {
      Vector3f w = {
        u.x - v.x,
        u.y - v.y,
        u.z - v.z
      };
      return w;
    }, py::is_operator());

  // create the "transforms" module and add methods to it
  auto m_transforms = m.def_submodule("transforms");
  m_transforms.def("dot_v3f", &core::transforms::dot_v3f);
  m_transforms.def("cross_v3f", &core::transforms::cross_v3f);
}
