#include <iostream>

int main() {
  int a = 0;

  auto lambda = [&a]() {
    std::cout << "キャプチャした変数: " << a << std::endl;
    a++; // 参照でキャプチャした変数を変更する。
  };

  lambda();

  // ラムダ式の中で変更が加えられている。
  std::cout << "元の変数: " << a << std::endl;

  a = 42; // キャプチャもとの変数を変更する。

  lambda(); // キャプチャした変数は変更されている。
}