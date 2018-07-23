#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

class Foo {
  std::string s;
  std::vector<int> v;

  public:
  Foo(const std::string &s, const std::vector<int> &v): s(s), v(v) {
    std::cout << "Foo(std::string &s, std::vector<int> &v)\n";
  }

  ~Foo() {
    std::cout << "~Foo()\n";
  }

  Foo(const Foo &f): s(f.s), v(f.v) {
    std::cout << "Foo(const Foo &f)\n";
  }

  Foo(Foo &&f) noexcept : s(std::move(f.s)), v(std::move(f.v)) {
    std::cout << "Foo(Foo &&f)\n";
  }
};

int main() {

  Foo f("Hello", std::vector({ 42 }));
  Foo f2(f);
  Foo f3(std::move(f2));


  std::vector<Foo> vf;

  std::cout << "Starting the loop\n";
  for (int i = 0; i < 3; ++i) {
    std::cout << "Loop #" << i << "\n";
    #if 1
    Foo f = Foo("Foo", { i });
    vf.emplace_back(std::move(f));
    #else
    vf.emplace_back("Foo", { i });
    #endif
  }

  return 0;
}

