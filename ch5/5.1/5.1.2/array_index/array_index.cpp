#include <iostream>

int main() {
  int array[] = { 0, 1, 2, 3};
  int* ptr = array;

  ptr += 2; // ポインターを2つ進める

  std::cout << *ptr << std::endl; // 2

  ++ptr; // ポインターを1つ進める
  std::cout << *ptr <<std::endl; // 3

  ptr -= 2; // ポインターを2つ戻す
  std::cout << *ptr << std::endl; // 1

  --ptr; // ポインターを1つ戻す
  std::cout << *ptr << std::endl; // 0
}