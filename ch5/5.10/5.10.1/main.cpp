#include <iostream>

class C {
  int a; // キャプチャしたいメンバー変数

public:
  void show_a() {
    [a]() { // エラー。メンバー変数を直接キャプチャできない
      std::cout <<"C::a = " << a << std::endl;
    }();
  }
};