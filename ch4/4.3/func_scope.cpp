#include <iostream>

class A {
public:
  ~A();
};

A::~A() {
  std::cout << "デストラクター呼び出し" << std::endl;
}

void function_scope(int i) {
  A a; // 関数スコープから抜けるときにデストラクターが呼ばれる
  std::cout << "関数スコープ" << std::endl;

  if (i > 0) {
    return ; // 関数の処理がここから呼び出し元に移る
  }

  std::cout << "if文のあと" << std::endl;
}

int main() {
  // if 文の条件が真の場合なので、return で関数から抜ける
  function_scope(10);
  std::cout << std::endl;

  // if 文の条件が偽の場合なので、関数スコープの終わりまで処理が進む
  function_scope(-10);

}