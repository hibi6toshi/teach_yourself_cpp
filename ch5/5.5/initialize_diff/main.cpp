#include <string>

class A {
  int m_v;
  std::string m_n;

public:
  A(int, std::string);
  A(float);
};

A::A(int v, std::string n) 
  : m_v(v), m_n{n} // OK 初期化リストで {} を使うことができる
{} 

A::A(float) 
  : A{-1, "float"} // OK 委譲コンストラクターで {} を使うことができる
{}

int main() {
  A ap(42, "0"); // 普通に（）を使って初期化
  A ab{42, "0"}; // OK () の代わりに {} を使って初期化

  A bp = A(42, "0"); // 関数形式の明示的な型変換
  A bb = A{42, "0"}; // OK 関数形式の明示的な型変換

  // A cp = (42, "0"); // これはエラーになる A(int, std::string) の呼び出しにならない。
  A cb = {42, "0"}; // OK bbの初期化と同じ

  A dp = (42, 0.0); // 要注意！A(int, std::string) ではなく A(float) が呼び出される
  // A db = {42, 0.0}; // エラー　doubleからstd::stringへの変換ができない

  double pi = 3.1415926536;
  A ep(pi); // OKだが、doubleからfloatへの暗黙変換が行われる
  A ep{pi}; // エラー　doubleからfloatへの暗黙変換が行われない
}