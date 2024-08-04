#include <iostream>

int main() {
  int array[] = {0, 1, 2, 3};

  std::cout << "先頭のアドレス: " << &array[0] << std::endl;

  int *ptr = array; // 配列からポインターへの暗黙変換

  std::cout << "ポインター: " << ptr << std::endl;
  std::cout <<"値: " << *ptr << std::endl;

  // 先頭のアドレス: 0x16b2cb008
  // ポインター: 0x16b2cb008
  // 値: 0

  // ポインターが持つアドレスも、間接参照した値も配列の先頭を指していることがわかります。
}