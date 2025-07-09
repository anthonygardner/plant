.PHONY: build clean install

build:
	cmake --build build --target install

clean:
	rm -fr build

install:
	uv pip install -e .
