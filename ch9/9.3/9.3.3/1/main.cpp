#include <iostream>

template <typename T>
class S {
public:
  static int value;
};

//　たとえstaticメンバー変数のかたがテンプレートパラメータに全く依存していなくても
// テンプレートの記述は必須
template <typename T>
int S<T>::value = 0;

int main() {
  // 初期値はどちらも0を与えている
  std::cout << "S<int>::value: " << S<int>::value << std::endl;
  std::cout << "S<float>::value: " << S<float>::value << std::endl;
  // 上記のS<int>とS<float>はそれぞれ別のクラスとして扱われる
  // なので、それぞれのstaticメンバー変数も別々に作られる

  // それぞれのstaticメンバー変数のアドレスを表示
  std::cout << "&S<int>::value: " << &S<int>::value << std::endl;
  std::cout << "&S<float>::value: " << &S<float>::value << std::endl;

  S<int>::value = 42; // int型で作ったstaticメンバー変数を変更する

  // staticメンバー変数自体がそれぞれのクラスの実態ごとに作られるので
  // S<float>::valueは変更されない
  std::cout << "S<int>::value: " << S<int>::value << std::endl;
  std::cout << "S<float>::value: " << S<float>::value << std::endl;

  // S<int>::value: 0
  // S<float>::value: 0
  // &S<int>::value: 0x102540000
  // &S<float>::value: 0x102540004
  // S<int>::value: 42
  // S<float>::value: 0
}