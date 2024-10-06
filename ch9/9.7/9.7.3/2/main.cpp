#include <iostream>
#include <utility> // std::move

void show_value_category(int& value) {
  std::cout << "参照" << std::endl;
}

void show_value_category(int&& vlaue) {
  std::cout << "右辺値参照" << std::endl;
}

// フォワーディング参照の仮引数をそのまま渡す
template<typename T>
void direct(T&& value) {
  show_value_category(value);
}

// フォワーディング参照の仮引数をstd::move()関数を通して渡す
template<typename T>
void move(T&& value) {
  show_value_category(std::move(value));
}

template<typename T>
void forward(T&& value) {
  // 完全転送
  show_value_category(std::forward<T>(value));
}

int main() {
  int i = 0;

  forward(i);
  forward(0);
  // 参照
  // 右辺値参照
}