#include <iostream>

int main() {
  int a = 0;
  auto lambda = [a]() { 
    // キャプチャリストにより、aがキャプチャされる
    std::cout << a << std::endl;
  };

  lambda();

  a = 42;

  // キャプチャされた変数の値は変更されない
  // 参照ではなく値がコピーされるため
  lambda();
}