#include <iostream>

int main() {
  // 変数show にラムダ式を投入する。
  auto show = [](int i) -> void {
    std::cout << i << std::endl;
  };

  show(42); // 42
}