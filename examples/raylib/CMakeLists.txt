add_executable(raylib_example main.c)

target_link_libraries(
    raylib_example
    PRIVATE
    ../../extern/raylib
)
