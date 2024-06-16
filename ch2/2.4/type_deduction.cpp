#include <iostream>

// 常に1を返す関数
int one() {
  return 1;
}

int main() {
  auto d = 3.14; // 3.14はdouble型なので、dはdouble型になる。
  d = 2.71f; // 2.71fはfloat型なので、double型に推論されたd には問題なく代入できる。
  
  std::cout << d << std::endl;

  // 型推論は関数呼び出しや数値計算などの式の結果からも行える。

  // one() はint型を返す関数なので、iはint型になる。
  auto i = one();

  i = 42.195; // i はint型なので、double型の値の代入では暗黙の型変換が行われ、小数点以下が切り捨てられる。
  std::cout << i << std::endl;
}