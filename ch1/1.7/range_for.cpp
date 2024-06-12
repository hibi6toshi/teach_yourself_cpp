#include <iostream>

int main() {
  int values[] = { -20, 10, 5, -40, 0, 10, -30};

  for(int value : values) {
    if (value < 0) {
      std::cout << "continue" << std::endl;
      continue;
    }
    if (value == 0) {
      std::cout << "break" << std::endl;
      break;
    }

    std::cout << "elem = " << value << std::endl;
  }

  std::cout << "ループの終了" << std::endl;
}