#include <iostream>

int main() {
  int array[] = { 0, 1, 2, 3, 4 };

  // から推論を使った範囲for文
  // 初期値の指定はしていないが、配列の要素の型に推論される
  for (auto e : array) {
    std::cout << e << std::endl;
  }
}