#include <iostream>

class A {
public:
  A();
  ~A();
};

A::A() {
  std::cout << "コンストラクター" << std::endl;
}

A::~A() {
  std::cout << "デストラクター" << std::endl;
}

A a; // グローバル変数

int main() {
  std::cout << "main関数" << std::endl;
}

// コンストラクター
// main関数
// デストラクター

// main()関数の前にグローバル変数aが定義されているので、main()関数の前にコンストラクターが呼び出される。