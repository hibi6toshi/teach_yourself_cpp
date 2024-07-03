#include <iostream>

void hello(){
  std::cout << "hello, world" << std::endl;
}

void goodbye() {
  std::cout << "goodbye, world" << std::endl;
}

int main() {
  #define hello goodbye // helloをgoodbyeに置き換える
  
  hello(); // マクロがhelloをgoodbyeに置き換える

  #undef hello // helloのマクロ定義を取り消す

  hello(); // マクロが定義される前は何も置き変わらない
}