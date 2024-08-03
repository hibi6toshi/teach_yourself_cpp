#include <iostream>

int main() {
  int&& i = 1; // 1への右辺値参照
  i = 0; // OK iは左辺値

  if (1 == 0) { // i = 0 によって、1が書き変わってしまったかどうか
    std::cout << "1 == 0" << std::endl;
  } else {
    std::cout << "1 != 0" << std::endl;
  }
  // 1 != 0
}