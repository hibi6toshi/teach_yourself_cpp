#include <iostream>

class Base {
  // 非公開な仮想関数
  virtual void method();

public:
  void call_method() { method(); }
};

void Base::method() {
  std::cout << "Base::method()" << std::endl;
}

class Derived : public Base {
  // 基底クラスで非公開となっていてもオーバーライドだけは可能
  void method() override;
};

void Derived::method() {
  std::cout << "Derived::method()" << std::endl;
  // Base::method(); // エラー Base::method() は非公開
}

int main() {
  Derived derived;
  derived.call_method();
  // -> Derived::method()
}