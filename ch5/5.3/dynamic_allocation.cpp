#include <iostream>

int* local() {
  int i = 42; //　ローカル変数
  return &i; // 注意: ダングリングポインター
}

int* dyn_alloc() {
  int* ptr = new int; // int型のオブジェクトを動的確保
  *ptr = 42; // 動的確保したint型のオブジェクトにアクセス
  return ptr; // 動的確保したものはスコープをでても破棄されない
}

int main() {
  // local() で作ったローカル変数はもう破棄されているので、このオブジェクトを参照してはいけない
  // int* l = local();
  // std::cout << *l << std::endl; // 42

  // 動的確保したオブジェクトは関数から戻っても破棄されないので有効
  int* d = dyn_alloc();
  std::cout << *d << std::endl; // 42

  delete d; // 自動で破棄されないので、不要になったらプログラマーが破棄する。
  // 破棄した後のオブジェクトはもう無効になっているので参照してはいけない
  // std::cout << *d << std::endl;

  return 0;
}
