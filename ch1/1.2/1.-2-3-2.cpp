#include <iostream>

void show_value(int a) {
  std::cout << a << std::endl;
  return; // ここに到着すると関数の実行は終了する

  // return 文で処理が戻っているため、この処理は実行されない
  std::cout << "show value" << std::endl;
}

int add(int a, int b) {
  int c = a + b;
  return c;
}

int main() {
  int x = add(10, 20);
  show_value(x);
}

// main関数はreturn文を省略できる。
// その場合、main関数の戻り値は0となる。
// main関数の戻り値は正常終了したかどうかの判定に使われ、0は正常終了を意味する。
// 一方、0以外の値を返すと、異常終了を意味する。