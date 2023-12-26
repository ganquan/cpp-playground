#include <fmt/color.h>
#include <fmt/core.h>
#include <fmt/ranges.h>

#include <vector>
#include <map>

int main() {
    fmt::print("Hello, world!\n");

    for (int i = 0; i < 3; i++) {
        fmt::print("i = {}\n", i);
    }

    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold, "Hello, {}!\n",
               "world");

    std::vector<int> vi{1, 2, 3};
    fmt::print("vi = {}\n", vi);

    std::map<int, int> m{{1,2}, {2,3}, {3,4}};
    fmt::print("m = {}\n", m);

    return 0;
}