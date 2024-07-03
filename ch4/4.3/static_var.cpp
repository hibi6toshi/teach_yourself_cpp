#include <iostream>

int count() {
  static int counter = 0;
  return ++counter;
}

int main() {
  std::cout << "1回目: " << count() << std::endl;
  std::cout << "2回目: " << count() << std::endl;
  std::cout << "3回目: " << count() << std::endl;
  // 1回目: 1
  // 2回目: 2
  // 3回目: 3
  // static変数の初期化は1回目のみ行われる
}