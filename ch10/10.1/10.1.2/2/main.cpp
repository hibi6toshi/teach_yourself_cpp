#include <iostream>

int main() {
  throw 0; // 誰も捕まえない例外オブジェクトを投げる

  // std::terminate()が呼ばれてプログラムが強制終了する
  // これ以降の処理は実行されない

  std::cout << "throw のあと" << std::endl;
  // terminate called after throwing an instance of 'int'
  // zsh: abort   
}