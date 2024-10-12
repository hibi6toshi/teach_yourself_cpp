#include <iostream>

template <typename Iterator, typename T>
T sum_all(Iterator first, Iterator last, T val) {
  while (first != last) {
    val += *first;
    ++first;
  }

  return val;
}

int main() {
  int array[10];
  for (int i = 0; i < 10; ++i) {
    array[i] = i;
  }

  int* first = &array[0];
  int* last = &array[10];

  std::cout << sum_all(first, last, 0) << std::endl;
}