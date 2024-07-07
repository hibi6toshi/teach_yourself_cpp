#include <iostream>

// 受け取った参照をそのまま返す関数　
int& id(int & i){
  return i;
}

int main() {
  int i = 42;
  auto j = id(i); // autoのみだと参照ではなく値がコピーされる

  auto&k = id(i); // 参照を返す関数を参照で受け取る

  i = 0;
  std::cout << "j: " << j << std::endl; // 42
  std::cout << "K: " << k << std::endl; // 0
}