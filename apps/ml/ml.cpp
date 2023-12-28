#include "spdlog/spdlog.h"
#include <fmt/core.h>
#include <mlpack/core.hpp>

int main() {
    spdlog::info(fmt::format("MLPACK version: {}.", mlpack::util::GetVersion()));
    spdlog::info(fmt::format("Hello from ml."));

    return 0;
}
