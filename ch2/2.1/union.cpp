#include <iostream>

// メンバー変数を3つ持った構造体
struct S {
  int a;
  int b;
  int c;
};

// メンバー変数を3つ持った共用体
union U {
  int a;
  int b;
  int c;
};

int main() {
  S s;

  // 構造体のメンバー変数はそれぞれのメモリー上に格納され、違ったアドレスを持つ。
  std::cout << "s.aのアドレス:" << &s.a << std::endl;
  std::cout << "s.bのアドレス:" << &s.b << std::endl;
  std::cout << "s.cのアドレス:" << &s.c << std::endl;

  U u;

  // 共用体のメンバー変数は同じアドレスを持つ。
  std::cout << "u.aのアドレス:" << &u.a << std::endl;
  std::cout << "u.bのアドレス:" << &u.b << std::endl;
  std::cout << "u.cのアドレス:" << &u.c << std::endl;
}