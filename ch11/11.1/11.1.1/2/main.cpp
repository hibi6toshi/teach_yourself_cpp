#include <iostream>
#include <typeinfo>

class Base {};

// 継承関係
class Derived : public Base {};

// 包括関係
class Composed {
  Base base;
};

int main() {
  // 継承関係があっても別の型として扱われる
  if (typeid(Base) == typeid(Derived)) {
    std::cout << "BaseとDerivedは同じクラスです" << std::endl;
  } else {
    std::cout << "BaseとDerivedは異なるクラスです" << std::endl;
  }

  // 包括関係も別の型として扱われる
  if (typeid(Base) == typeid(Composed)) {
    std::cout << "BaseとComposedは同じクラスです" << std::endl;
  } else {
    std::cout << "BaseとComposedは異なるクラスです" << std::endl;
  }
  // BaseとDerivedは異なるクラスです
  // BaseとComposedは異なるクラスです
}