#include <iostream>

std::string get_message(); // 前方宣言

int main() {
  auto msg = get_message(); // 定義がまだされていないが、宣言だけはされているので利用可能
  std::cout << msg << std::endl;
}

// 関数の実際の定義
std::string get_message() {
  return "Hello, forward declaration";
}