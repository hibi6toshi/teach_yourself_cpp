#include <iostream>

class A {
public:
  void foo();
};

void A::foo() {
  std::cout << "A::foo()" << std::endl;
}

void call_foo(A* pa) {
  pa->foo(); // ポインターを使ってメンバーにアクセス
             // (*pa).foo(); と書いても同じ
}

int main() {
  A a;
  call_foo(&a); // A::foo()
}