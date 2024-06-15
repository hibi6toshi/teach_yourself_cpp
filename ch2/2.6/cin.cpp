#include <iostream>

int main() {
  int i;
  std::cout << "数値を入力してください>"; // 改行はしない。
  std::cin >> i; // コンソールから入力を受け取り、iに代入する。

  std::cout << "入力された数値は\"" << i << "\"です。" << std::endl; // 改行する。
}