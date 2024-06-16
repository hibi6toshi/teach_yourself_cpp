#include <iostream>

union U {
  int a;
  int b;
  int c;
};

int main() {
  // 共用体の初期化リストは最初のメンバー変数に適用される。
  U u = { 42 };

  // u.b は u.a と同じアドレスを持つので、u.aと同じ値を持つ。
  std::cout << "u.b: " << u.b << std::endl;

  // u.c も u.a と同じアドレスを持つので、u.cを変更するとu.aも変更される。
  u.c = 1024;
  std::cout << "u.a: " << u.a << std::endl;
}