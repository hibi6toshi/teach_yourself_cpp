#include <iostream>

class BaseA {
  int value;

public:
  explicit BaseA(int value) : value{value} {}

  void show_baseA() {
    std::cout << "BaseA::show_baseA() = " << value << std::endl;
  }
};

class BaseB {
  int value;

public:
  explicit BaseB(int value) : value{value} {}

  void show_baseB() {
    std::cout << "BaseB::show_baseB() = " << value << std::endl;
  }
};

class Derived : public BaseA, public BaseB {
public:
  Derived(int a, int b);
};

Derived::Derived(int a, int b)
 : BaseA{a} // BaseAのコンストラクタを呼び出す
 , BaseB{b} // BaseBのコンストラクタを呼び出す
  {}

int main() {
  Derived derived{42, 72};
  derived.show_baseA();
  derived.show_baseB();
  // 出力
  // BaseA::show_baseA() = 42
  // BaseB::show_baseB() = 72
}