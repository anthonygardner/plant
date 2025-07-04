#include <gtest/gtest.h>

#include "plant/core/transforms.hpp"
#include "plant/core/types.hpp"

TEST(Vector3fTest, AdditionOperator) {
  plant::core::types::Vector3f u = {1.0, 2.0, 3.0};
  plant::core::types::Vector3f v = {-1.0, -2.0, -3.0};

  plant::core::types::Vector3f w = {
    u.x + v.x,
    u.y + v.y,
    u.z + v.z
  };

  EXPECT_EQ(w.x, 0.0);
  EXPECT_EQ(w.y, 0.0);
  EXPECT_EQ(w.z, 0.0);
}

TEST(Vector3fTest, SubtractionOperator) {
  plant::core::types::Vector3f u = {-1.0, -2.0, -3.0};
  plant::core::types::Vector3f v = {-1.0, -2.0, -3.0};

  plant::core::types::Vector3f w = {
    u.x - v.x,
    u.y - v.y,
    u.z - v.z
  };

  EXPECT_EQ(w.x, 0.0);
  EXPECT_EQ(w.y, 0.0);
  EXPECT_EQ(w.z, 0.0);
}

TEST(Vector3fTest, DotProductOperator) {
  plant::core::types::Vector3f u = {1.0, 2.0, 3.0};
  plant::core::types::Vector3f v = {3.0, 2.0, 1.0};

  float dot = plant::core::transforms::dot_v3f(u, v);

  EXPECT_EQ(dot, 10.0);
}

TEST(Vector3fTest, CrossProductOperator) {
  plant::core::types::Vector3f u = {1.0, 2.0, 3.0};
  plant::core::types::Vector3f v = {3.0, 2.0, 1.0};

  plant::core::types::Vector3f w = plant::core::transforms::cross_v3f(u, v);

  EXPECT_EQ(w.x, -4.0);
  EXPECT_EQ(w.y, 8.0);
  EXPECT_EQ(w.z, -4.0);
}
