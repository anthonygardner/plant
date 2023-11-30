import pytest

from plant import types


def test_types_latlonalt():
    lla = types.LatLonAlt(-0.123, 0.588, 10.0, types.AltType.MeanSeaLevel)

    assert lla.lat == pytest.approx(-0.123)
    assert lla.lon == pytest.approx(0.588)
    assert lla.alt == pytest.approx(10.0)
    assert lla.alt_type == types.AltType.MeanSeaLevel


def test_types_cartpos():
    p = types.CartPos(0.023, -1.993, 3934.242425, types.ReferenceFrame.EarthCenteredEarthFixed)

    assert p.x == pytest.approx(0.023)
    assert p.y == pytest.approx(-1.993)
    assert p.z == pytest.approx(3934.242425)
    assert p.rf == types.ReferenceFrame.EarthCenteredEarthFixed


def test_types_cartvel():
    v = types.CartVel(100.234, 0.0004, -0.943, types.ReferenceFrame.NorthEastDown)

    assert v.vx == pytest.approx(100.234)
    assert v.vy == pytest.approx(0.0004)
    assert v.vz == pytest.approx(-0.943)
    assert v.rf == types.ReferenceFrame.NorthEastDown


def test_types_cartacc():
    a = types.CartAcc(0.0, 0.0, -9.81, types.ReferenceFrame.EarthCenteredInertial)

    assert a.ax == pytest.approx(0.0)
    assert a.ay == pytest.approx(0.0)
    assert a.az == pytest.approx(-9.81)
    assert a.rf == types.ReferenceFrame.EarthCenteredInertial


def test_types_attrpy():
    rpy = types.AttRpy(30.0, -15.0, 60.0) # TODO(acg): add units field

    assert rpy.roll == pytest.approx(30.0)
    assert rpy.pitch == pytest.approx(-15.0)
    assert rpy.yaw == pytest.approx(60.0)


def test_types_attquat():
    q = types.AttQuat(1.0, 0.0, 0.0, 0.0)

    assert q.w == pytest.approx(1.0)
    assert q.x == pytest.approx(0.0)
    assert q.y == pytest.approx(0.0)
    assert q.z == pytest.approx(0.0)


def test_types_state():
    p = types.CartPos(0.023, -1.993, 3934.242425, types.ReferenceFrame.EarthCenteredEarthFixed)
    v = types.CartVel(100.234, 0.0004, -0.943, types.ReferenceFrame.NorthEastDown)
    a = types.CartAcc(0.0, 0.0, -9.81, types.ReferenceFrame.EarthCenteredInertial)
    lla = types.LatLonAlt(-0.123, 0.588, 10.0, types.AltType.MeanSeaLevel)
    rpy = types.AttRpy(30.0, -15.0, 60.0)
    q = types.AttQuat(1.0, 0.0, 0.0, 0.0)

    assert isinstance(p, types.CartPos)
    assert isinstance(v, types.CartVel)
    assert isinstance(a, types.CartAcc)
    assert isinstance(lla, types.LatLonAlt)
    assert isinstance(rpy, types.AttRpy)
    assert isinstance(q, types.AttQuat)

    state = types.State(p, v, a, lla, rpy, q) # TODO(acg): make state fields accessible as, e.g, state.x == p.x

    assert state.p.x == pytest.approx(0.023)
    assert state.p.y == pytest.approx(-1.993)
    assert state.p.z == pytest.approx(3934.242425)
    assert state.p.rf == types.ReferenceFrame.EarthCenteredEarthFixed

    assert state.v.vx == pytest.approx(100.234)
    assert state.v.vy == pytest.approx(0.0004)
    assert state.v.vz == pytest.approx(-0.943)
    assert state.v.rf == types.ReferenceFrame.NorthEastDown

    assert state.a.ax == pytest.approx(0.0)
    assert state.a.ay == pytest.approx(0.0)
    assert state.a.az == pytest.approx(-9.81)
    assert state.a.rf == types.ReferenceFrame.EarthCenteredInertial

    assert state.lla.lat == pytest.approx(-0.123)
    assert state.lla.lon == pytest.approx(0.588)
    assert state.lla.alt == pytest.approx(10.0)
    assert state.lla.alt_type == types.AltType.MeanSeaLevel

    assert state.rpy.roll == pytest.approx(30.0)
    assert state.rpy.pitch == pytest.approx(-15.0)
    assert state.rpy.yaw == pytest.approx(60.0)

    assert state.q.w == pytest.approx(1.0)
    assert state.q.x == pytest.approx(0.0)
    assert state.q.y == pytest.approx(0.0)
    assert state.q.z == pytest.approx(0.0)
