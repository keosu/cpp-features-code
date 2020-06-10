#include <experimental/filesystem>
#include <iostream>
#include <unordered_map>
#include <string_view> 
#include <experimental/string_view>
namespace s = std::experimental; 

namespace fs = std::experimental::filesystem;

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
  byte b{0};         // OK
  byte d = byte{1};  // OK
}

 



void stringview_test() {
    auto sv = s::string_view("HELLOW");
    
    std::cout << "sizeof string_view: " << sizeof(sv) << '\n';
    std::cout << "max_size: " << sv.max_size() << '\n';
    std::cout << "length: " << sv.length() << ", size: " << sv.size() << '\n';

    std::cout << sv << '\n';

    auto sv2 = sv.substr(3, sv.size() - 6);
    sv.remove_prefix(3);
    sv.remove_suffix(3);
    
    // [] returns const value, cannot assign:
    //sv[10] = 'a';
    
    std::cout << "sv == sv2: " << (sv == sv2) << '\n';
    std::cout << "sv : " << sv << '\n';
    std::cout << "sv2: " << sv2 << '\n';
     
}

void fs_test() {
  fs::path p(fs::current_path());

  std::cout << p << std::endl;
  std::cout << p.parent_path() << std::endl;

  std::cout << "directory_iterator:\n";
  fs::directory_iterator d(p.parent_path());
  for (auto sd : d) {
    auto status = sd.status();
    std::cout << "    " << std::hex << (size_t)status.permissions() << " "
              << (int)status.type() << " " << sd << '\n';
  }

  std::cout << "recursive_directory_iterator:\n";
  for (auto sd : fs::recursive_directory_iterator(p.parent_path())) {
    auto status = sd.status();
    std::cout << "    " << std::hex << (size_t)status.permissions() << " "
              << (int)status.type() << " " << sd.path().filename() << '\n';
  }
}
int main(int argc, char **argv) {
  structure_binding();
  x();
  stringview_test();
  return 0;
}