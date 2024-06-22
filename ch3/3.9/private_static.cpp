#include <iostream>

class S {
  static int count; // インスタンスの数を数えるstaticメンバー変数
public:
  S();
  ~S();

  static void show_count(); // staticメンバー関数
};

int S::count = 0; // staticメンバー変数の定義と初期化

S::S() {
  // インスタンスが生成されたらインクリメント
  ++count;
}

S::~S() {
  // インスタンスが破棄されたらデクリメント
  --count;
}

void S::show_count() {
  std::cout << "S::count: " << count << std::endl;
}

void function() {
  S a;
  a.show_count(); // インスタンスはmain()のa とこの関数内のaの2つ
}

int main() {
  S a;
  a.show_count(); // 1
  function(); // 2
  a.show_count(); // `function()`内のインスタンスは破棄されているので1
}