#include <iostream>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../src/utils/parser.h"

using ::testing::EndsWith;

TEST(ParserTest, Directories) {
  plant::utils::Directories d;

  EXPECT_THAT(d.PLANT_CONFIGS, EndsWith("configs"));
  EXPECT_THAT(d.PLANT_CORE, EndsWith("core"));
  EXPECT_THAT(d.PLANT_SENSORS, EndsWith("sensors"));
  EXPECT_THAT(d.PLANT_SRC, EndsWith("src"));
  EXPECT_THAT(d.PLANT_UTILS, EndsWith("utils"));
}

TEST(ParserTest, Files) {
  plant::utils::Files f;

  EXPECT_THAT(f.MAIN_YML, EndsWith("main.yml"));
}
