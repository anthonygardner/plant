from plant import structs


def test_struct_latlonalt():
    lla = structs.LatLonAlt()


def test_struct_cartpos():
    pos = structs.CartPos()


def test_struct_cartvel():
    vel = structs.CartVel()


def test_struct_cartacc():
    acc = structs.CartAcc()


def test_struct_attrpy():
    rpy = structs.AttRpy()


def test_struct_attquat():
    q = structs.AttQuat()


def test_struct_state():
    state = structs.State()
