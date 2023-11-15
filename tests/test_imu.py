def test_imu_constructor():
    from plant import sensors
    imu = sensors.IMU(0, 0)

    assert imu.wx == 0.0
