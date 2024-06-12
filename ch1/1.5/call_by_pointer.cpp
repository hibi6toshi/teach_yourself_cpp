#include <iostream>

void nochange(int i) {
  // 仮引数を変更するが、呼び出した変数自体は変更されない。
  i = 42;
}

void set42 (int* pi) {
  // 仮引数で渡されたアドレスが指し示す変数に42を代入する
  *pi = 42;
}

int main() {
  int i = 0; // iを0で初期化

  nochange(i); // 変数i が持っている値だけを渡す

  // iは変更されない
  std::cout << i << std::endl; // 0

  set42(&i); // iのアドレスを渡す

  // set42関数内でiに42を代入しているため、iの値が42になる
  std::cout << i << std::endl; // 42
}