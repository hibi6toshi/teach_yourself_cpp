#include <iostream>

class BaseA {
public:
  void method_baseA() {
    std::cout << "BaseA::method_baseA()" << std::endl;
  }
};

class BaseB {
public:
  void method_baseB() {
    std::cout << "BaseB::method_baseB()" << std::endl;
  }
};

class Derived
  : public BaseA
  , public BaseB {

  public:
    void method_derived() {
      std::cout << "Derived::method_derived()" << std::endl;
    }
};

int main() {
  Derived derived;

  derived.method_baseA(); // BaseAから継承したメンバー関数の呼び出し
  derived.method_baseB(); // BaseBから継承したメンバー関数の呼び出し
  derived.method_derived(); // Derivedクラスのメンバー関数の呼び出し

  BaseA& base_a = derived; // DerivedはBaseAの派生クラスなので、BaseA として扱える
  // base_a.method_baseB(); // エラー BaseAの参照を使っているので、BaseBのメンバー関数は呼び出せない
  // base_a.method_derived();  // エラー BaseAの参照を使っているので、Derivedのメンバー関数は呼び出せない

  BaseB& base_b = derived; // DerivedはBaseBの派生クラスなので、BaseB として扱える
  // base_b.method_baseA(); // エラー BaseBの参照を使っているので、BaseAのメンバー関数は呼び出せない
  // base_b.method_derived();  // エラー BaseBの参照を使っているので、Derivedのメンバー関数は呼び出せない
}