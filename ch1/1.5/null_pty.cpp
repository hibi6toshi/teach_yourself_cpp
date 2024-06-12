#include <iostream>

int main() {
  // 0を代入することでもヌルポインターを作成できるが、数値の代入と混同するので、nullptr を推奨
  int* ptr = 0;

  std::cout << ptr << std::endl;

  ptr = nullptr;

  std::cout << ptr << std::endl;
}