//
// Created by User on 28.07.2020.
//

#include "debug.hpp"
#include <Common/common.hpp>

namespace fs = std::filesystem;

void printDebugInfo() {
    auto path = fs::current_path();
    Logger::printInfo((std::string) reinterpret_cast<const char *>(path.c_str()));
}
