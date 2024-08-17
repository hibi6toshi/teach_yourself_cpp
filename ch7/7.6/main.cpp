#include <iostream>

class Base {
public:
  void method_base() {
    std::cout << "Base: " << this << std::endl;
  }
};

// Derivedは仮想基底クラスとしてBaseを継承する
class DerivedA : virtual public Base {
public:
  void method_derivedA() {
    std::cout << "DerivedA: " << this << std::endl;
  }
};

// DerivedBは仮想基底クラスとしてBaseを継承する
class DerivedB : virtual public Base {
public:
  void method_derivedB() {
    std::cout << "DerivedB: " << this << std::endl;
  }
};

// DerivedA も DerivedB も Baseから派生しているが、Baseは仮想基底クラスに指定されているので、
// MoreDerivedにはBaseはただ1つだけ存在する。
class MoreDerived : public DerivedA, public DerivedB {
public:
  void method_more_derived() {
    std::cout << "MoreDerived: " << this << std::endl;
  }
};

int main() {
  MoreDerived more_derived;

  // これらのメンバー関数はこれまで通り普通に継承されるので呼び出せる
  more_derived.method_derivedA();
  more_derived.method_derivedB();
  more_derived.method_more_derived();

  // 今までは曖昧だったが、Baseは仮想基底クラスなので曖昧にならずに呼び出すことができる
  more_derived.method_base();

  // こちらも曖昧にならずBaseの参照を取得できる
  Base& base = more_derived;
  // 出力
  // DerivedA: 0x16d4af088
  // DerivedB: 0x16d4af090
  // MoreDerived: 0x16d4af088
  // Base: 0x16d4af088

  std::cout << "DerivedA: " << std::endl;
  DerivedA& derived_a = more_derived;
  derived_a.method_base();
  std::cout << std::endl;

  std::cout << "DerivedB: " << std::endl;
  DerivedB& derived_b = more_derived;
  derived_b.method_base();
  // 出力
  // DerivedA: 
  // Base: 0x16f0b7088

  // DerivedB: 
  // Base: 0x16f0b7088
  // 同じアドレスなので、Baseはただ1つだけ存在していることがわかる
}