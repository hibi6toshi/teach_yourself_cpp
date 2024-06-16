#include <iostream>

void callee();

int main() {
  int a = 0;
  callee();

  auto lambda = []() {
    // エラー: 'a' was not captured for this lambda function
    std::cout << a << std::endl;
  };
  lambda();
}

void callee() {
  // エラー: 'a' was not declared in this scope
  std::cout << a << endl;
}