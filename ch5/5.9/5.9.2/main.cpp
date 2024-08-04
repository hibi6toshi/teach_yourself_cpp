#include <iostream>

int identity(int v) {
  return v;
}

int square(int v) {
  return v * v;
}

int main() {
  // 関数リファレンスを宣言し、identityで初期化する。
  int (&func)(int) = identity;

  // 関数リファレンスを経由して、identityを呼び出す。
  std::cout << "func(4): " << func(4) << std::endl;

  // func = square; // エラー: 関数リファレンスは再代入できない
}