#include <iostream>

enum class Category {
  Value1, // 先頭は明示的に指定しないと暗黙的に0から始まる。
  Value2, // 値を省略した場合、前の値から1ずつ増加する。
  Value3 = 100, // 途中で値を指定することもできる。
  Value4, // 途中で値を指定した場合、次の値はその値から1ずつ増加する。(この場合は101)
};

int main() {
  // 列挙体の変数を宣言してValue3で初期化する。
  Category cat = Category::Value3;

  // 列挙体の値に対応した整数を得る。
  std::cout << static_cast<int>(cat) << std::endl;
  // 列挙体変数は整数値を持っているが、明示的にキャストしないと整数値に変換できない。
}