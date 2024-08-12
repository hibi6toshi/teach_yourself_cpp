# include <iostream>

class Base {
public:
  virtual void method();
};

void Base::method() {
  // 基底クラスでの実装 : 派生クラスから呼び出されることを期待する
  std::cout << "Base::method()" << std::endl;
}

class Derived : public Base {
public:
  void method() override;
};

void Derived::method() {
  std::cout << "Derived::method()" << std::endl;
  Base* base = this; // 基底クラスへのポインターを取得
  base->method(); // 基底クラスのメンバーを呼んでいるつもり

  //　上記では仮想関数によって、基底クラスのポインター・参照が派生クラスのオブジェクトを使うようにしているため、
  // 派生クラスのメンバー関数が呼ばれる。

  // 基底クラスのメンバー関数を呼びたい場合は、以下のように書く
  Base::method(); // 基底クラスを指定してメンバー関数を呼ぶ
  this->Base::method(); // このように書くこともできる
}

int main() {
  Derived derived;
  derived.method(); // オーバーライドしたメンバー関数の呼び出し。
}