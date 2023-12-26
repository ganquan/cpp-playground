#include "spdlog/spdlog.h"
#include <fmt/core.h>

int main() {
  spdlog::info(fmt::format("Hello World!"));
  return 0;
}
