.PHONY: build.cpp build.python clean install notebook test.cpp test.python

build.cpp:
	cmake --build build --target install -j$(nproc)

build.python:
	uv pip install -e .

clean:
	rm -fr build

commit:
	uv run cz c

install:
	uv pip install -e .

notebook:
	uv run marimo edit notebooks/sim.py --host 0.0.0.0 --headless --no-token

test.cpp:
	cd build && ctest && cd -

test.python:
	uv run pytest