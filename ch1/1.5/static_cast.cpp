#include <iostream>

int main() {
  char c = 99;

  std::cout << c << std::endl; // cは文字型なので、文字として出力される
  std::cout << static_cast<int>(c) << std::endl; // cをint型にキャストして出力
}