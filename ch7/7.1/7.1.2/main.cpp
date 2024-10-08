#include <iostream>

class Base {
// 被保護メンバー
protected:
  void protected_member() {
    std::cout << "Base::protected_member()" << std::endl;
  }
};

class Derived : public Base {
public:
  void member_test();
};

void Derived::member_test() {
  // OK 気的クラスの被保護メンバーには派生クラスからアクセス可能
  protected_member();
}

int main() {
  Derived derived;

  // エラー publicで派生しても被保護メンバーは外部からアクセスできない
  // derived.protected_member();

  // OK 公開メンバーには外部からアクセス可能
  derived.member_test();
}