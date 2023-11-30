import pytest

from plant import sensors


def test_imu_default_constructor():
    imu = sensors.IMU()

    assert imu.wx == 0.0
    assert imu.wy == 0.0


def test_set_imu_constructor_by_value():
    imu = sensors.IMU(13.23, -64.0)

    assert imu.wx == pytest.approx(13.23)
    assert imu.wy == pytest.approx(-64.0)


def test_set_imu_constructor_by_name():
    imu = sensors.IMU(wx=-0.859, wy=0.1224)

    assert imu.wx == pytest.approx(-0.859)
    assert imu.wy == pytest.approx(0.1224)
