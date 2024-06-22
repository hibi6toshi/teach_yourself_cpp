#include <iostream>

int main() {
  // このソースファイル名を出力する
  std::cout << "_FILE__: " << __FILE__ << std::endl;

  // この行の行番号を出力する
  std::cout << "__LINE__: " << __LINE__ << std::endl;

  // この関数の関数名を出力する
  std::cout << "__func__: " << __func__ << std::endl;

  // 参照しているC++のバージョンを出力する
  std::cout << "__cplusplus: " << __cplusplus << std::endl;

  int line = __LINE__; // 変数に行番号を代入

  // line は現在の行番号ではなく、代入されたときの行番号が出力される
  std::cout << "line: " << line << ", __LINE__: " << __LINE__ << std::endl;
}