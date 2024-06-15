#include <iostream>

// 値の1の型を推論し、その型を戻り値の方として使う
decltype(1) one() {
  return 1;
}

int main() {
  auto i = one(); // autoを使った型推論
  
  decltype(i) j; // 変数iから型を推論し、jの型として使う
                 // 型は推論されるので、初期値は不要
  j = 42.195; // j はint型に推論されているので、暗黙の型変換が行われる。

  std::cout << j << std::endl;
}