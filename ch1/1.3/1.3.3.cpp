#include <iostream>

int main() {
  int i =42;
  std::cout << "sizeof(i): " << sizeof(i) << std::endl;
  // expression(式)の結果のサイズもsizeof演算子で取得できる
  std::cout << "sizeof(i + 1): " << sizeof(i + 1) << std::endl;
  // 型のサイズは環境によって異なる
}