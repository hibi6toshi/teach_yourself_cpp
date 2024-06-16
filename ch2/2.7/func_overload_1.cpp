#include <iostream>

void show_value(int a) {
  std::cout << a << std::endl;
}

// 3つの整数を受け取り、それらの和を返す関数sum()のオーバーロード
int sum(int a, int b, int c) {
  int d = a + b + c;
  return d;
}

// 2つの整数を受け取り、それらの和を返す関数sum()
int sum(int a, int b) {
  int c = a + b;
  return c;
}

// ラップした関数でオーバーロード時の定義の負担を減らす
// int sum(int a, int b) {
//   return sum(a, b, 0);
// }

int main() {
  int x = sum(10, 20);
  show_value(x);

  int y = sum(10, 20, 30);
  show_value(y);
}

