
#include <iostream>
#include <vector>

int main(int argc, char** argv) {
  auto v = std::vector{1, 2, 3};
  for (auto& e : v) {
    std::cout << e;
  }
}