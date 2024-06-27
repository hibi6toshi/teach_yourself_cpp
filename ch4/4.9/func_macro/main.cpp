#include <iostream>

void hello() {
  std::cout << "hello, macro" << std::endl;
}

#define id(name) name // 引数で受け取ったものにそのまま置き換える

int main() {
  id(hello)(); // hello() と同じ 関数引き出しのように関数形式マクロid を呼び出す。

  // 関数形式マクロを展開した後のmain()関数は以下のようになる。
  // int main() {
  //   hello(); // id がhelloに置き換わったので、hello() と同じ
  // }
}