#include <iostream>

class Base {
public:
  virtual void method1() {
    std::cout << "Base::method1()" << std::endl;
  }

  virtual void method2() {
    std::cout << "Base::method2()" << std::endl;
  }
};

class Derived : public Base {
public:
  // このメンバーはこれ以上オーバーライドできない
  void method1() final {
    std::cout << "Derived::method1()" << std::endl;
  }

  // こちらは単なるオーバーライド
  void method2() override {
    std::cout << "Derived::method2()" << std::endl;
  }
};

class MoreDerived : public Derived {
public:
  // エラー Derivedでfinal指定されているのでオーバーライドすることはできない
  // void method1() override;

  // OK オーバーライドをさらにオーバーライドすることはできる
  void method2() override {
    std::cout << "MoreDerived::method2()" << std::endl;
  }
};