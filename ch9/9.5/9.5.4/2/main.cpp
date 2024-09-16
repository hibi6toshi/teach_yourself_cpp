// 特殊化を使って、型推論されたかを判定する
#include <iostream>
#include <string>

// ヘルパークラスの前方宣言
template<typename T>
class helper;

// intのときに使われるヘルパークラス
template<>
class helper<int> {
public:
  static std::string name() { return "int"; }
};

// doubleのときに使われるヘルパークラス
template<>
class helper<double> {
public:
  static std::string name() { return "double"; }
};

template<typename T>
struct A {
  T value;
};

template<typename T>
void deduce(A<T> a) {
  // 推論されたTを使ってヘルパークラスのstaticメンバー関数を呼び出す
  std::cout << helper<T>::name() << std::endl;
}

int main() {
  A<int> ai;

  deduce(ai); // ai から推論されるTを表示する

  A<double> ad;

  deduce(ad); // ad から推論されるTを表示する

  // int
  // double
}



