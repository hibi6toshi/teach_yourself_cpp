#include <memory>
#include <utility>
#include <iostream>

class A {
public:
  A() {
    std::cout << "コンストラクター" << std::endl;
  }

  ~A() {
    std::cout << "デストラクター" << std::endl;
  }
};

std::unique_ptr<A> allocate() {
  std::cout << "allocate()" << std::endl;
  std::unique_ptr<A> ptr{new A{}};

  // メモリ領域の所有権を戻り値として関数スコープの外側に移動する
  return std::move(ptr);
}

int main() {
  {
    std::unique_ptr<A> ptr; // 空のstd::unique_ptr。

    std::cout << "関数呼び出しの前" << std::endl;

    ptr = allocate(); // allocate()が確保したメモリ領域の所有権を受け取る

    std::cout << "関数呼び出しの後" << std::endl;
  }

  std::cout << "スコープの後" << std::endl;
  // 関数呼び出しの前
  // allocate()
  // コンストラクター
  // 関数呼び出しの後
  // デストラクター
  // スコープの後
}