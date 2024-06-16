#include <iostream>

int main() {
  int value = 42; // int 型の変数
  int other = 0; // int 型の別の変数
  int* pointer = &value; // 変数 value へのポインター
  int& reference = value; // 変数 value への参照

  std::cout << "valueのアドレスは" << &value << "で、値は" << value << "です" << std::endl;
  std::cout << "otherのアドレスは" << &other << "で、値は" << other << "です" << std::endl;
  std::cout << "pointerの持つアドレスは" << pointer << "で、値は" << *pointer << "です" << std::endl;
  std::cout << "referenceのアドレスは" << &reference << "で、値は" << reference << "です" << std::endl;
  //  valueのアドレスは0x16bb0b02cで、値は42です
  // otherのアドレスは0x16bb0b028で、値は0です
  // pointerの持つアドレスは0x16bb0b02cで、値は42です
  // referenceのアドレスは0x16bb0b02cで、値は42です

  std::cout << "=========================" <<std::endl;

  pointer = &other; // pointer が持つアドレスを other のアドレスに変更
  reference = other; // 参照先をvalue から other に変更したつもりだが、value に代入される
  
  std::cout << "valueのアドレスは" << &value << "で、値は" << value << "です" << std::endl;
  std::cout << "otherのアドレスは" << &other << "で、値は" << other << "です" << std::endl;
  std::cout << "pointerの持つアドレスは" << pointer << "で、値は" << *pointer << "です" << std::endl;
  std::cout << "referenceのアドレスは" << &reference << "で、値は" << reference << "です" << std::endl;
  // valueのアドレスは0x16bb0b02cで、値は0です
  // otherのアドレスは0x16bb0b028で、値は0です
  // pointerの持つアドレスは0x16bb0b028で、値は0です
  // referenceのアドレスは0x16bb0b02cで、値は0です
}