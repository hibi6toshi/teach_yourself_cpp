#include <iostream>

int main() {
  int value = 42; // int 型の変数
  
  std::cout << "valueのアドレスは" << &value << "で、値は" << value << "です" << std::endl;

  int& ref = value; // 変数 value への参照

  std::cout << "refのアドレスは、" << &ref << "で、値は" << ref << "です" << std::endl;

  ref = 0; // 変数 value への参照を使って value の値を変更

  std::cout << "valueのアドレスは" << &value << "で、値は" << value << "です" << std::endl;

  // valueのアドレスは0x16f153034で、値は42です
  // refのアドレスは、0x16f153034で、値は42です
  // valueのアドレスは0x16f153034で、値は0です
}