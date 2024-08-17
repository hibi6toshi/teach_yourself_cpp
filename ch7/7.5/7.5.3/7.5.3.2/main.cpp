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

  // DerivedAが継承したBase::show()の呼び出し
  more_derived.DerivedA::show();

  // DerivedBが継承したBase::show()の呼び出し
  more_derived.DerivedB::show();

  // DerivedA の参照を経由して、Baseの参照を取得
  Base& base = static_cast<DerivedA&>(more_derived);

  // DerivedA の参照を経由したので、DerivedAが継承したBase::show() の呼び出し
  base.show();

  // DerivedB の参照を経由して、Baseの参照を取得
  Base& base2 = static_cast<DerivedB&>(more_derived);

  // DerivedB の参照を経由したので、DerivedBが継承したBase::show() の呼び出し
  base2.show();

  // 出力
  // this: 0x16bbb3058
  // value: 42
  // this: 0x16bbb305c
  // value: 72
  // this: 0x16bbb3058
  // value: 42
  // this: 0x16bbb305c
  // value: 72
}