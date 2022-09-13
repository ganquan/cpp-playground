#include <fmt/core.h>
#include <fmt/color.h>

int main() {

  fmt::print("Hello, world!\n");

  for(int i = 0; i < 3; i++) {
    fmt::print("i = {}\n", i);

  }

  return 0;
}