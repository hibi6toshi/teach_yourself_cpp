#include <iostream>

class Base {
public:
  virtual void foo(int i) {
    std::cout << "Base::foo()" << std::endl;
  }
};

template <typename T>
class Derived : public Base {
public:
  // Baseのfooをオーバーライドしているつもりだが、
  // Tに渡されるテンプレート引数によって動作が異なる
  void foo(T val) override {
    std::cout << "Derived::foo()" < std::endl;
  }
};

int main() {
  Derived<int> di; // fooがオーバーライドされる場合
  // 仮想関数を経由した派生クラスのメンバー呼び出し
  static_cast<Base&>(di).foo(0);
  
  // エラー　仮想関数の仮引数の型が異なってしまいオーバーライドが失敗する
  // Derived<float> df;

  // Baseクラスのfoo関数のシグネチャはvoid foo(int)ですが、Derivedクラスのfoo関数はvoid foo(T)というシグネチャです。 
  // Derived<int>の場合はfoo(int)となり、一見Baseクラスのfoo(int)と同じように見えますが、Baseクラスの関数とは異なる型（テンプレート引数に依存）で定義されているため、仮想関数のオーバーライドが失敗します。
  // このため、コンパイラはoverrideキーワードを指定しているにもかかわらず、Base::foo(int)を正しくオーバーライドできず、コンパイルエラーとなります。具体的には、Derivedクラスのfoo関数はBaseのfoo関数とは別物として扱われ、ポリモーフィズムが正しく動作しません。
}