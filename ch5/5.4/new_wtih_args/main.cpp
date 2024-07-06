#include <iostream>

int main() {
  int* p = new int(42); // int型のオブジェクトを動的確保

  std::cout << *p << std::endl; // 42

  delete p; // delete 演算子は通常のまま
}