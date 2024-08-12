#include <iostream>

class Base {
public:
  // 仮想関数
  virtual void method();

  void method_not_virtual() {
    std::cout << "Base::method_not_virtual()" << std::endl;
  }
};

void Base::method() {
  std::cout << "Base::method()" << std::endl;
}

class Derived : public Base {
public:
  // Base::method() をオーバーライド
  void method() override;

  void method_not_virtual();
};

void Derived::method() {
  std::cout << "Derivedでオーバーライドしたメンバー関数" << std::endl;
}

void Derived::method_not_virtual() {
  std::cout << "Derived::method_not_virtual()" << std::endl;
}

int main() {
  Derived derived;
  Base& base = derived; // 基底クラスへの参照を取得

  // 基底クラスへの参照経由であっても仮想関数はDerivedでオーバーライドした方が呼ばれる
  base.method();
  // -> Derivedでオーバーライドしたメンバー関数

  base.method_not_virtual();
  // -> Base::method_not_virtual()
  derived.method_not_virtual();
  // -> Derived::method_not_virtual()
}