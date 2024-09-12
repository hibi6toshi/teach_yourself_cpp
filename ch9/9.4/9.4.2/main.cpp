#include <iostream>

// プライマリテンプレート
template <typename A, typename B, typename C>
struct Tuple {
  A a;
  B b;
  C c;

  void show() const {
    std::cout << '{' << a << ", " << b << ", " << c << '}' << std::endl;
  }
};

// 2番目のテンプレートパラメーターをvoid限定した部分特殊化
template <typename A, typename C> // 限定していない部分を埋めるためのテンプレートパラメーター
struct Tuple<A, void, C> {
  A a;
  C c;

  void show() const {
    std::cout << '{' << a << ", " << c << '}' << std::endl;
  }
};

int main() {
  // 2番目のテンプレートパラメーターがvoidなので、部分特殊化が使われる。
  Tuple<int, void, float> t = {42, 3.1415};

  t.show();
  // {42, 3.1415}
}