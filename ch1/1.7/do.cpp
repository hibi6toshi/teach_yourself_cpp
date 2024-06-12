#include <iostream>

int main() {
  int values[] = { -20, 10, 5, -40, 0, 10, -30}; 
  int i = 0;

  do {
    if (values[i] < 0) {
      std::cout << "continue" << std::endl;
      i++;
      continue;
    }

    if (values[i] == 0) {
      std::cout << "break" << std::endl;
      break;
    }

    std::cout << "elem = " << values[i] << std::endl;
    i++;
  } while (i < 7);

  std::cout << "ループの終了" << std::endl;

}