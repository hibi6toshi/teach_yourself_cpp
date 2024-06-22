#include <iostream>

class Base {
public:
  void foo();
};

void Base::foo() {
  std::cout << "Base::foo()" << std::endl;
}

class Derived : public Base {
public:
  using Base::foo; // 基底クラスのfoo()を派生クラスにも公開する
  
  void foo(int i);
};

void Derived::foo(int i) {
  std::cout << "Derived::foo(int)" << std::endl;
}

int main() {
  Derived derived;
  derived.foo(); // 基底クラスのfoo()が呼ばれる
  derived.foo(42); // 派生クラスのfoo(int)が呼ばれる
}