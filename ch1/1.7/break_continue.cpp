#include <iostream>

int main() {
  int values[] = { -20, 10, 5, -40, 0, 10, -30};

  int i = 0;
  while (i < 7) {
    // 配列の先頭から見ていき、負の数だったらスキップして、0だったらループを抜ける。
    if (values[i] < 0) {
      std::cout << "continue" << std::endl;
      ++i;
      continue; // この行でループの先頭に戻る。
    }
    if (values[i] == 0) {
      std::cout << "break" << std::endl;
      break; // この行でループを抜ける。
    }
    std::cout << "elem = " << values[i] << std::endl;
    ++i;
  }
  
  std::cout << "ループの終了" << std::endl;
}