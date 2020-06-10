#include <iostream>
#include <tuple>

using namespace std;

#include <memory>

struct Vec3 {
  int x, y, z;
  Vec3() : x(0), y(0), z(0) {}
  Vec3(int x, int y, int z) : x(x), y(y), z(z) {}
  friend ostream& operator<<(ostream& os, Vec3& v) {
    return os << '{' << "x:" << v.x << " y:" << v.y << " z:" << v.z << '}';
  }
};

void test_makeunique() {
  unique_ptr<Vec3> v1 = make_unique<Vec3>();
  unique_ptr<Vec3> v2 = make_unique<Vec3>(0, 1, 2);
  // Create a unique_ptr to an array of 5 elements
  unique_ptr<Vec3[]> v3 = make_unique<Vec3[]>(5);

  cout << "make_unique<Vec3>():      " << *v1 << '\n'
       << "make_unique<Vec3>(0,1,2): " << *v2 << '\n'
       << "make_unique<Vec3[]>(5):   " << '\n';
  for (int i = 0; i < 5; i++) {
    cout << "     " << v3[i] << '\n';
  }
}

auto get_student(int id) {
  if (id == 0) return make_tuple(3.8, 'A', "Lisa Simpson");
  if (id == 1) return make_tuple(2.9, 'C', "Milhouse Van Houten");
  if (id == 2) return make_tuple(1.7, 'D', "Ralph Wiggum");
  throw invalid_argument("id");
}

void test_tuple() {
  tuple<int, string, int> a{1, "name", 120};
  cout << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << ", " << endl;

  get<0>(a) = 3;
  get<1>(a) = "sdf";
  cout << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << ", " << endl;

  cout << get<2>(get_student(1)) << endl;

  auto s = get_student(0);
  cout << "s" << endl;
}

int main(int argc, char** argv) {
  //   test_tuple();
  test_makeunique();
  return 0;
}