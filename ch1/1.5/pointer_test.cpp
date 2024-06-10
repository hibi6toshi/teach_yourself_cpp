#include <iostream>

int main() {
  int i = 0;
  // ポインターを使って、iを42に変更する
  int* p = &i;
  *p = 42;

  std::cout << i << std::endl;
}

