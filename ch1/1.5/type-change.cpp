#include <iostream>

int main() {
  float f = -1234.5678f; // 負の浮動小数点数
  std::cout << f << std::endl;

  int i = f; // 浮動小数点数から整数への暗黙的な型変換
             // この場合、小数点以下は切り捨てられる
  std::cout << i << std::endl;

  unsigned int u = i; // 整数から符号なし整数への暗黙的な型変換
                      // この場合、負の値は正の値に変換される
  std::cout << u << std::endl;

  unsigned short s = u; // 符号なし整数から符号なし短整数への暗黙的な型変換
                        // この場合、値が範囲内であれば変換される
                        // 符号なし胆整数の範囲に収まらない値を変換しようとすると、値が範囲内に収められる
  std::cout << s << std::endl;

  u = s; // 符号なし短整数から符号なし整数への暗黙的な型変換
  std::cout << u << std::endl;

  f = u; // 符号なし整数から浮動小数点数への暗黙的な型変換
  std::cout << f << std::endl;
}