#include <iostream>

int foo(int value) {
  // 何か複雑な処理
  std::cout << "foo: " << value << std::endl;
  return value;
}

bool is_even(int value) { // 偶数ならtrueを返す関数
  return value % 2 == 0;
}

bool is_zero(int value) {
  return value == 0;
}

int main() {
  // foo(42)の戻り値が0はない偶数の場合に分岐させているが、
  // 複雑な処理をするfoo()関数を2回呼び出している

  // foo: 42
  // foo: 42
  // foo(42)は偶数で0ではありません
  // if (is_even(foo(42)) && !is_zero(foo(42))){
  //   std::cout << "foo(42)は偶数で0ではありません" << std::endl;
  // }

  // 初期化構文付きif文を使うと、foo()関数を1回だけ呼び出せる
  if(int result = foo(42); is_even(result) && !is_zero(result)) {
    std::cout << "foo(42)は偶数で0ではありません" << std::endl;
  }
}