#include <iostream>

class Base { // 基底クラス
public:
  virtual void foo(); // 仮想関数の宣言
};

void Base::foo() { // 仮想関数の定義 virtualは不要
  std::cout << "Base::foo()" << std::endl;
}

class Derived : public Base { // 派生クラス
public:
  void foo() override; // 仮想関数のオーバーライド
  // void foo(int i) override; // エラー 対応する基底クラスの仮想関数がない
  void foo(int i); // 単なるオーバーロードは可能
};

void Derived::foo() { // 仮想関数のオーバーライド overrideは不要
  std::cout << "Derived::foo()" << std::endl;
}

void Derived::foo(int i) {
  std::cout << "Derived::foo(int)" << std::endl;
}

int main() {
  Derived derived;
  derived.foo(); // 仮想関数呼び出し
  derived.foo(42); // 仮想関数ではないオーバーロードの呼び出し
}