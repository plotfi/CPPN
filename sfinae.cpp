#include <stdio.h>
#include <iostream>

template <bool Cond, typename Result>
struct enable {};

template <typename Result> 
struct enable<true, Result> {
   using type = Result;
};


template <typename T> void func(typename T::whatever &foo) {
   std::cout << __func__ << " 1\n";
}

template <typename T> void func(T &foo) {
   std::cout << __func__ << " 2\n";
}


//void func(int foo) {
//   std::cout << __func__ << " 3\n";
//}
//

template <typename T>
std::enable_if_t<std::is_integral<T>::value> take( T foo) {
   std::cout << "first: " << foo << "\n";
}

template <typename T>
std::enable_if_t<!std::is_integral<T>::value> take( T foo) {
   std::cout << "second: " << foo << "\n";
}



int main() {

  printf("foobar\n");

  int foo = 10;
  func(foo);

  double bar = 10.1;
  take(bar);
  take(foo);

  return 0;
}

