#include <iostream>

int main() {
  int values[] = { -20, 10, 5, -40, 0, 10, -30};

  // インデックス変数の宣言と、条件式と、進める処理を1箇所に書くことができる。
  for (int i =0; i < 7; i++) {
    if (values[i] < 0){
      std::cout << "continue" << std::endl;
      continue;
    }
    if (values[i] == 0) {
      std::cout << "break" << std::endl;
      break;
    }

    std::cout << "elem = " << values[i] << std::endl;
  }

  std::cout << "ループの終了" << std::endl;
}