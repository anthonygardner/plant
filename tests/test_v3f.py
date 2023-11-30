from plant import transforms
from plant import types


def test_add_v3f():
    u = types.Vector3f(1, 2, 3)
    v = types.Vector3f(-1, -2, -3)
    w = u + v

    assert w.x == 0.0
    assert w.y == 0.0
    assert w.z == 0.0


def test_sub_v3f():
    u = types.Vector3f(-1, -2, -3)
    v = types.Vector3f(-1, -2, -3)
    w = u - v

    assert w.x == 0.0
    assert w.y == 0.0
    assert w.z == 0.0


def test_dot_v3f():
    u = types.Vector3f(1, 2, 3)
    v = types.Vector3f(3, 2, 1)

    dot = transforms.dot_v3f(u, v)
    assert dot == 10.0


def test_cross_v3f():
    u = types.Vector3f(1, 2, 3)
    v = types.Vector3f(3, 2, 1)
    w = transforms.cross_v3f(u, v)

    assert w.x == -4.0
    assert w.y == 8.0
    assert w.z == -4.0
