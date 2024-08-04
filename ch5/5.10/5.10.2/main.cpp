#include <iostream>

class C {
  int a;

public:
  void show_a() {
    [this]() { // OK メンバー変数ではなく、thisポインターをキャプチャ
      // OK this->a と同じ意味になる。
      std::cout << "C::a = " << a << std::endl;
    }();
  }
};

class D {
  int a;

public:
  void set_a(int value) {
    [this, value]() { // mutable指定していない
      a = value; // ok. this->a = value; と同じ意味で aにvalueを代入
    }();
  }
};

class E {
  int a; 

public:
  void set_a(int value) const { /// const指定をする。
    [this, value]() mutable { // 例えラムダ式にmutable指定をしたとしても
      // エラー　コピーしたthisポインターの型はconst E* なので、変更はできない。
      a = value;
    }();
  }
};