import subprocess

def test_cli():
    p = subprocess.Popen([
        "plant-cli", "-h",
        ],
        stdout=subprocess.PIPE,
    )

    out, err = p.communicate()

    assert out.decode("utf-8") == "-h"
