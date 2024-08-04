#include <iostream>

int main() {
  int&& i = 0;
  int&& j = 0; // 0からもう一つの右辺値参照を作る。

  std::cout << &i << std::endl;
  std::cout << &j << std::endl;
  // 同じ右辺値を使った右辺値参照であっても、右辺値参照として参照するときにはそれぞれ別のオブジェクトが作られているというわけです。
  // 0x16bbbf06c
  // 0x16bbbf068
}