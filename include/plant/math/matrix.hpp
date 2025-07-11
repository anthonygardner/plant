#pragma once

#include <array>

namespace plant::math {

template<int rows, int cols>
class Matrix {
private:
    std::array<float, rows * cols> data;

public:
    Matrix() : data{} {
        for (int i = 0; i < rows * cols; i++) {
            data[i] = static_cast<float>(i);
        }
    }

    // Read an element
    const float& operator()(int row, int col) const {
        return data[row * cols + col];
    }

    // Write an element
    float& operator()(int row, int col) {
        return data[row * cols + col];
    }
};

}  // namespace plant::math