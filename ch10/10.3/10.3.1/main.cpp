#include <new> // std::bad_alloc例外に必要
#include <iostream>

int main() {
  try {
    int* ptr = new int;
    // ... 何かしらの処理
    delete ptr;
  } catch (std::bad_alloc& e) {
    std::cout << "メモリ割り当てに失敗しました" << std::endl;
  }
}