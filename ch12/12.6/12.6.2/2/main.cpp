#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  std::vector v = { 1, 2, 3 ,2, 1 };

  auto c = std::count(v.begin(), v.end(), 2);
  std::cout << "vに2は" << c << "個あります" << std::endl;

  c = std::count_if(v.begin(), v.end(), [](int v) { return v < 2; });
  std::cout << "vに2未満の要素は" << c << "個あります" << std::endl;
}