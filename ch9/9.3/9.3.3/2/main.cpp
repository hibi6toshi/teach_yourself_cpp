#include <iostream>

// テンプレートになっていないstaticメンバーだけを持つクラスを作成して、それを継承する。
// これにより、テンプレートのstaticメンバー変数を共有できて、それぞれのクラスのstaticメンバー変数を共有できる
struct S_shared {
  static int value;
};

// クラスのテンプレート間で共有できる変数
int S_shared::value = 0;

template <typename T>
class S : public S_shared { 
};

int main() {
  std::cout << "S<int>::value: " << S<int>::value << std::endl;
  std::cout << "S<float>::value: " << S<float>::value << std::endl;

  // それぞれのstaticメンバー変数のアドレスを表示
  std::cout << "&S<int>::value: " << &S<int>::value << std::endl;
  std::cout << "&S<float>::value: " << &S<float>::value << std::endl;

  S<int>::value = 42; // int型の実態を通してstaticメンバー変数を変更する

  // クラステンプレートの実態は異なるが、大元の規定クラスはただ1つなので変数が共有される
  std::cout << "S<int>::value: " << S<int>::value << std::endl;
  std::cout << "S<float>::value: " << S<float>::value << std::endl;

  // S<int>::value: 0
  // S<float>::value: 0
  // &S<int>::value: 0x10251c004
  // &S<float>::value: 0x10251c004
  // S<int>::value: 42
  // S<float>::value: 42
}
