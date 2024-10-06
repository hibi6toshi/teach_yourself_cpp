#include <iostream>

//　関数テンプレートでの積和演算
// この段階ではまだテンプレートパラメータのTは具体的な型が決まっていない
template <typename T>
T fused_multiply_add(T a, T b, T c) { // 戻り値の型にも仮引数にもテンプレートパラメータを使うことができる。
  T r = a * b + c; // ローカルの変数の型にもテンプレートパラメータを使うことができる。
  return r;
}

int main() {
  // 関数テンプレートをintで実体化して呼び出し
  std::cout << fused_multiply_add<int>(1, 2, 3) << std::endl;
  // 5

  // 関数テンプレートをfloatで実体化して呼び出し
  std::cout << fused_multiply_add<float>(1.23456f, 1.23456f, 1.23456f) << std::endl;
  // 2.7587

  // 関数テンプレートをdoubleで実体化して呼び出し
  std::cout << fused_multiply_add<double>(1.23456, 1.23456, 1.23456) << std::endl;
  // 2.7587
}