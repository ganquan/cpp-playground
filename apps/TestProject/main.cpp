#include <fmt/core.h>
#include <fmt/format.h>
#include <spdlog/spdlog.h>

int main() {
    spdlog::info(fmt::format("Hello World!"));
    return 0;
}
