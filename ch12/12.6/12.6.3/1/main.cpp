#include <vector>
#include <iostream>
#include <algorithm>

int main() {
  std::vector v = { 10, -3, 0, 4, 2 };
  auto c = v; // sort()は変更するのでコピーしておく

  std::sort(c.begin(), c.end()); // 昇順にソート
  for (auto e : c) {
    std::cout << e << " ";
  }
  std::cout << std::endl;

  c = v;
  // 降順にソート
  std::sort(c.begin(), c.end(), [](int l, int r) { return l > r; });
  for (auto e : c) {
    std::cout << e << " ";
  }

  std::cout << std::endl;
}