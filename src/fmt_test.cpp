#include <fmt/color.h>
#include <fmt/core.h>

int main() {
    fmt::print("Hello, world!\n");

    for (int i = 0; i < 3; i++) {
        fmt::print("i = {}\n", i);
    }

    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold, "Hello, {}!\n",
               "world");

    return 0;
}