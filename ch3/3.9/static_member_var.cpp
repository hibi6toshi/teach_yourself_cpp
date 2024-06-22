#include <iostream>

class S {
public:
  static int num; // staticメンバー変数の宣言
};

int S::num = 42; // staticメンバー変数の定義と初期化

int main() {
  std::cout << S::num << std::endl;
  S::num = 456;
  S s;

  // 特定のインスタンスからもアクセスできるが、実態は同じものを指している
  std::cout << s.num << std::endl;
}