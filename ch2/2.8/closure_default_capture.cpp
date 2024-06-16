#include <iostream>

int main() {
  int a = 0;
  float b = 3.14; // 変数bはラムダ式の内部で使われないのでキャプチャされない　

  auto lambda = [=]() {
    // aを使っているので、コンパイラーが自動的にaをキャプチャする
    std::cout << a << std::endl;
  };

  lambda();
}