#include <iostream>

int sum_all(int* first, int* last, int val) {
  while (first != last) {
    val += *first; // firstが指す要素にアクセス
    ++first; // 次の要素へ
  }

  return val;
}

int main() {
  int array[10];
  for (int i = 0; i <10; ++i) {
    array[i] = i;
  }

  int* first = &array[0];
  int* last = &array[10];

  std::cout << sum_all(first, last, 0) << std::endl;
}