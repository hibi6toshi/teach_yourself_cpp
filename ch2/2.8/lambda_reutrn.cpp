#include <iostream>

int main() {
  auto return_void = []() {
    std::cout << "何も返さないラムダ式" << std::endl;
  };

  auto return_int = []() {
    return 42;
  };

  // // エラー returnの型が全て同じではない
  // auto rectified_linear_unit = [](float x) {
  //   if (0 <= x) {
  //     return 0; // int 型
  //   }

  //   return x; // float 型
  // };

  auto rectified_linear_unit1 = [](float x) { // OK 戻り値の型が同じ
    if (0 <= x) {
      return 0.0f; // float型
    }
    return x; // float型
  };

  auto rectified_linear_unit2 = [](float x) -> float { // OK
    if (0 <= x) {
      return 0; // int -> floatへの暗黙的型変換が行われる。
    }

    return x; // float型
  };

}