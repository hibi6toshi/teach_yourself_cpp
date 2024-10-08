#include <iostream>

// 整数の積和演算
int fused_multiply_add(int a, int b, int c) {
  int r = a * b + c;
  return r;
}

// floatの積和演算
float fused_multiply_add(float a, float b, float c) {
  // 関数の本体での計算は整数と同じ
  float r = a * b + c;
  return r;
}

int main() {
  // 整数版のオーバーロード呼び出し
  std::cout << fused_multiply_add(1, 2, 3) << std::endl;
  // 5

  // float版のオーバーロード呼び出し
  std::cout << fused_multiply_add(1.23456f, 1.23456f, 1.23456f) << std::endl;
  // 2.7587

  // 想定していないdouble型を使った呼び出し。
  // この呼び出しはint型のオーバーロードがよばれる
  std::cout << fused_multiply_add(1.23456, 1, 1.23456) << std::endl;
  // 2
}