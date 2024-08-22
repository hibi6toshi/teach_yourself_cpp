#include <iostream>

class Base {
public:
  void method_base();
};

void Base::method_base() {
  std::cout << "Base::method_base()" << std::endl;
}

class Derived : public Base {
public:
  void method_derived();
};

void Derived::method_derived() {
  std::cout << "Derived::method_derived()" << std::endl;
}

int main() {
  Derived derived;

  // OK DerivedはBaseのメンバー関数を継承しているので呼び出せる。
  derived.method_base();

  // OK Derivedのメンバー関数なので呼び出せる。
  derived.method_derived();

  // 基底クラウへの参照は派生クラスからも作れる。
  Base& base = derived;

  // OK Baseのメンバー関数へはBaseの参照から辿ることができる。
  base.method_base();

  // NG Derivedのメンバー関数へはBaseの参照からは辿れない。
  // base.method_derived();

  // NG 基底クラスから派生クラスへの参照は作れない。（実際のインスタンスが派生クラスであっても）
  // Derived& derived2 = base;
}