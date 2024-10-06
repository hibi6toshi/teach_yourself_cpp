#include <iostream>

template<typename T>
struct A {
  T value;
};

// 実引数からテンプレートパラメーターTが推論される
template<typename T>
T get_value(A<T> a) {
  return a.value;
}

int main() {
  A<int> ai{42};

  // A<int>からテンプレートパラメーターはintと推論される
  std::cout << get_value(ai) << std::endl;

  A<double> ad{3.1415};

  // A<double>からテンプレートパラメーターはdoubleと推論される
  std::cout << get_value(ad) << std::endl;

  // 42
  // 3.1415
}