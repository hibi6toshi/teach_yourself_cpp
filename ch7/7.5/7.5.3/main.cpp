#include <iostream>

class Base {
  int value;

public:
  Base(int value) : value{value} {}
  void show();
};

void Base::show() {
  std::cout << "this: " << this << std::endl
            << "value: " << value << std::endl;
}

class DerivedA : public Base {
public: 
  DerivedA(int value) : Base{value} {}
};

class DerivedB : public Base {
public:
  DerivedB(int value) : Base{value} {}
};

// DerivedAもDerivedBもBaseから派生していることに注意
class MoreDerived : public DerivedA, public DerivedB {
public:
  MoreDerived(int d_a, int d_b) : DerivedA{d_a}, DerivedB{d_b} {}
};

int main() {
  MoreDerived more_derived{42, 72};

  // DerivedA と DerivedBのどちらのBase::show()が使われる？
  more_derived.show();
  // main.cpp:36:16: error: request for member 'show' is ambiguous
  //  36 |   more_derived.show();
  //     |                ^~~~
  //  どちらのBase::show()を使うかが曖昧なのでエラー

  // DerivedAとDerivedB、どちらのBaseへの参照が代入される？
  Base& base = more_derived;

  base.show();
}