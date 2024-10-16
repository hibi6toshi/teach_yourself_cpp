#include <iostream>
#include <list>

int main() {
  std::list il = { 0, 1, 2, 3, 4 };
  auto top = il.begin();

  auto next = il.begin();
  ++next; // nextは1を指す

  auto bottom = il.end();
  --bottom; // bottomは4を指す

  il.erase(top); // 削除された要素を指すとtopは無効になるが
  il.push_back(5); // それ以外(next, bottom)は無効にならない

  for (auto iter = next; iter != bottom; ++iter) {
    std::cout << *iter << " ";
  }
  std::cout << std::endl;
}