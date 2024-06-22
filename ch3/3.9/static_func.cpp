#include <iostream>

class S {
  static int count; // インスタンスの数を記録するstaticメンバー変数

public:
  S();
  ~S();

  static void show_count(); // staticメンバー関数の宣言
};

int  S::count = 0; // staticメンバー変数の実態を定義して初期化する

S::S() {
  ++count;
}

S::~S() {
  --count;
}

void S::show_count() {
  std::cout << "S::count: " << count << std::endl;
}

int main() {
  // どのインスタンスにも紐づかないstaticメンバー関数は、クラス名を使って呼び出す
  S::show_count();
  S a;

  a.show_count(); // インスタンスからも呼び出せるが、実態は同じものを指している
}