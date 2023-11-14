def test_import_plant():
    import plant


def test_import_plant_core():
    import plant.core


def test_from_plant_import_core():
    from plant import core


def test_from_plant_core_import_transforms():
    from plant.core import transforms


def test_from_plant_core_import_structs():
    from plant.core import structs


def test_add_v3f():
    from plant.core import Vector3f as v3f

    u = v3f(1, 2, 3)
    v = v3f(-1, -2, -3)
    w = u + v

    assert w.x == 0.0
    assert w.y == 0.0
    assert w.z == 0.0


def test_sub_v3f():
    from plant.core import Vector3f as v3f

    u = v3f(-1, -2, -3)
    v = v3f(-1, -2, -3)
    w = u - v

    assert w.x == 0.0
    assert w.y == 0.0
    assert w.z == 0.0


def test_dot_v3f():
    from plant.core import transforms
    from plant.core import Vector3f as v3f

    u = v3f(1, 2, 3)
    v = v3f(3, 2, 1)

    dot = transforms.dot_v3f(u, v)
    assert dot == 10.0


def test_cross_v3f():
    from plant.core import transforms
    from plant.core import Vector3f as v3f

    u = v3f(1, 2, 3)
    v = v3f(3, 2, 1)
    w = transforms.cross_v3f(u, v)

    assert w.x == -4.0
    assert w.y == 8.0
    assert w.z == -4.0
