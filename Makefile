.PHONY: build clean install notebook

build:
	cmake --build build --target install -j$(nproc)

clean:
	rm -fr build

install:
	uv pip install -e .

notebook:
	uv run marimo edit notebooks/sim.py --host 0.0.0.0 --headless --no-token