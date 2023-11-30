build:
	mkdir -p build && cd build && cmake .. && cmake --build . -j 16

clean:
	rm -fr build
