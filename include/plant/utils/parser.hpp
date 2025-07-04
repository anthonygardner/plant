/** @file Header file parsing .yaml configuration file(s) */

#pragma once

#include <filesystem>

namespace plant {
namespace utils {

class Directories {
   public:
    std::filesystem::path PLANT_UTILS =
        std::filesystem::path(__FILE__).parent_path();
    std::filesystem::path PLANT_SRC = PLANT_UTILS.parent_path();
    std::filesystem::path PLANT_CORE = PLANT_SRC / "core";
    std::filesystem::path PLANT_SENSORS = PLANT_SRC / "sensors";

    std::filesystem::path PLANT_ROOT = PLANT_SRC.parent_path();
    std::filesystem::path PLANT_CONFIGS = PLANT_ROOT / "configs";
};

class Files : Directories {
   public:
    std::filesystem::path MAIN_YML = Directories::PLANT_CONFIGS / "main.yml";
};

}  // namespace utils
}  // namespace plant
