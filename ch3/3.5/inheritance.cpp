#include <iostream>

class Base { // 基底クラス
public:
  void foo();
}; 

void Base::foo() {
  std::cout <<"foo()" << std::endl;
}

class Derived : public Base { // 派生クラス
public:
  void bar(); // 派生クラス独自のメンバー関数
};

void Derived::bar() {
  std::cout << "bar()" << std::endl;
}

int main() {
  Base base;
  base.foo(); // 基底クラスのメンバー関数を呼び出す
  // base.bar(); // エラー: 基底クラスにbar()はない

  Derived derived;
  derived.foo(); // 基底クラスのメンバー関数を呼び出す
  derived.bar(); // 派生クラス独自のメンバー関数を呼び出す
}
