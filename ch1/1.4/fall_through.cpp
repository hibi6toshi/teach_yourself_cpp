#include <iostream>

int main() {
  int a = 2;

  switch (a) {
    case 1: // fall through
    case 2: // fall through
    case 3:
      std::cout << "aは1か2か3です" << std::endl;
      return 0;
  }
  // return された場合は、ここには到達しない
  std::cout << "残りの処理" << std::endl;
}