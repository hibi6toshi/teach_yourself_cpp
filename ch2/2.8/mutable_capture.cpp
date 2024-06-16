#include <iostream>

int main() {
  int a = 0;

  auto lambda = [a]() mutable {
    a = 42; // aは変更可能な状態でキャプチャされる
    std::cout << "キャプチャした変数: " << a << std::endl;
  };

  lambda(); // 42 

  // lambdaの中でaを変更しても、元の変数aには影響しない
  std::cout << "元の変数: " << a << std::endl; // 0
}