import pytest

from plant import types


def test_struct_latlonalt():
    lla = types.LatLonAlt(-0.123, 0.588, 10.0, types.AltType.MeanSeaLevel)

    assert lla.lat == pytest.approx(-0.123)
    assert lla.lon == pytest.approx(0.588)
    assert lla.alt == pytest.approx(10.0)
    assert lla.alt_type == types.AltType.MeanSeaLevel


def test_struct_cartpos():
    pos = types.CartPos()


def test_struct_cartvel():
    vel = types.CartVel()


def test_struct_cartacc():
    acc = types.CartAcc()


def test_struct_attrpy():
    rpy = types.AttRpy()


def test_struct_attquat():
    q = types.AttQuat()


def test_struct_state():
    state = types.State()
