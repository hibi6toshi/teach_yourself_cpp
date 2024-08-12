#include <iostream>

class Base {
  void private_member() {
    std::cout << "Base::private_member()" << std::endl;
  }

public:
  void public_member() {
    std::cout << "Base::public_member()" << std::endl;
  }
};

class Derived : private Base { // 非公開で派生
public:
  void member_test();
};

void Derived::member_test() {
  // private_member(); // エラー　基底クラスの非公開メンバーにはアクセス不可
  public_member(); // OK 基底クラスの公開メンバーにはアクセス可能
}

int main() {
  Base base;
  Derived derived;

  // base.private_member(); // エラー　基底クラスの非公開メンバーにはアクセス不可
  base.public_member(); // OK 派生クラスがprivateで派生していても、それは基底クラスには影響しない

  // derived.private_member(); // エラー　派生クラスの非公開メンバーにはアクセス不可
  // derived.public_member(); // エラー privateで派生しているため、非公開メンバーとなっている

  derived.member_test(); // OK 派生クラスのメンバー関数を介して基底クラスの公開メンバーにアクセス
}