from plant.math import Quaternion


def test_instantiate_quaternion():
    q = Quaternion()

def test_add_quaternions():
    p = Quaternion(0, 1, 2, 3)
    q = Quaternion(1, 2, 3, 4)

    assert p.w + q.w == 1
    assert p.x + q.x == 3
    assert p.y + q.y == 5
    assert p.z + q.z == 7

def test_quaternion_to_matrix():
    q = Quaternion()
    m = q.to_matrix()

    assert m is not None, "to_matrix() returned None"
