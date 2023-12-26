#include "spdlog/spdlog.h"
#include <fmt/core.h>
#include <functional>

void measure(std::string label, std::function<void()> const &lambda) {
    auto start = std::chrono::high_resolution_clock::now();

    lambda();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;

    spdlog::info(fmt::format("measure {} cost: {} ms.", label, elapsed.count()));
}

int main(int argc, char **argv) {

    measure("test measure", []() {
        spdlog::info("Enter lambda.");
        spdlog::info("Leave lambda.");
    });

    spdlog::info("end of main()");
    return 0;
}
