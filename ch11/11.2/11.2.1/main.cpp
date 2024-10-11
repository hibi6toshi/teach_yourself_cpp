#include <iostream>

int main() {
  const char* message = "Hello, C-style cast";

  // OK C形式はconst修飾子を無視したキャストができる
  void* ptr = (void*)message;

  std::cout << (char*)ptr << std::endl;
  // Hello, C-style cast
  // void*型は任意の非const型へのポインターを代入できる特別なポインター型です。
  // しかし、void*型のポインターからはキャスト演算子を使わなければ戻すことができません。
}