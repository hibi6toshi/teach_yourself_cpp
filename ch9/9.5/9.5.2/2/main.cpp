#include <iostream>

template<typename Type>
Type lea(Type ptr, Type stride, Type count, Type offset) {
  return ptr + stride * count + offset;
}

template<typename P, typename S, typename C, typename O>
auto lea2(P ptr, S stride, C count, O offset) {
  return ptr + stride * count + offset;
}

int main() {
  int i = 0;
  // 引数の型が1つだけ異なる場合、コンパイラーがどちらの型をTypeに使用するか判断できずエラーになる
  // std::cout << lea(&i, 16, 4, 2) << std::endl;
  // main.cpp:4:6: note:   template argument deduction/substitution failed:
  // main.cpp:11:19: note:   deduced conflicting types for parameter 'Type' ('int*' and 'int')

  // テンプレートパラメーターが引数の型にそれぞれ異なるものを使っていた場合、それぞれのテンプレートパラメーターがそれぞれの引数から推論される
  std::cout << lea2(&i, 16, 4, 2) << std::endl;
  // int*, int, int, int でそれぞれ推論される
  // 0x16dd1b124
}