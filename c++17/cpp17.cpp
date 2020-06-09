#include <iostream>
#include <unordered_map>

void structure_binding() {
  using Coordinate = std::pair<int, int>;

  const auto [x, y] = Coordinate{3, 4};

  std::unordered_map<std::string, int> mapping{{"a", 1}, {"b", 2}, {"c", 3}};

  // Destructure by reference.
  for (const auto &[key, value] : mapping) {
    std::cout << key << " : " << value << std::endl;
  }
}

void x() {
  char x = u8'x';

  enum byte : unsigned char {};
  byte b{0};          // OK
  byte c{-1};         // ERROR
  byte d = byte{1};   // OK
  byte e = byte{256}; // ERROR
}

int main(int argc, char **argv) { return 0; }