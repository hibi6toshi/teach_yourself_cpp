#include <iostream>

int main() {
  // 文字列リテラルで初期化
  char hello[] = "hello";

  // 文字リテラルの配列として初期化
  char array[6] = { 'a', 'r', 'r'}; 
  array[3] = 'a'; // 一文字ずつ代入しても良い
  array[4] = 'y';
  array[5] = '\0'; // 文字列の終端を示すヌル文字列(Null Character)を追加

  std::cout << "hello , " << array << std::endl; 
}