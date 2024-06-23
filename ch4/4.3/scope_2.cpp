#include <iostream>

int main() {
  int i = 42;

  {
    int i = 72; // 異なるスコープでは同じ名前のローカル変数を作ることができる。

    // 現在のスコープから遡って最も内側にある変数が使われる。
    std::cout << "inner: " << &i << ": " << i << std::endl;

    i = 0; // 内側の変数に代入される
  }

  // 内側のスコープの変数は無効になっているので、外側の変数が使われる。
  std::cout << "outer: " << &i << ": " << i << std::endl;

  // inner: 0x16d0eb038: 72
  // outer: 0x16d0eb03c: 42
}