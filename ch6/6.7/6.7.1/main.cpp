#include <iostream>

class int_observer_ptr {
  int* pointer;

public:
  explicit int_observer_ptr(int* pointer) : pointer(pointer) { }

  int& operator*() const; // 感染参照演算子
};

// ポインタークラス自体はconstであっても、
// ポインターが指し示す先はconstではないのd非const参照を返す
int& int_observer_ptr::operator*() const {
  return *pointer;
}

int main() {
  int value = 0;

  int_observer_ptr pointer{&value};

  std::cout << *pointer << std::endl;

  value = 42;

  std::cout << *pointer << std::endl;
  // 0
  // 42
}