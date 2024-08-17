# 7.5 多重継承
C++では複数のクラスを基底クラスにして継承することができます。
これを**多重継承**といいます。

BaseAとBaseBの両方を継承したクラスはDerivedは、BaseAとBaseBのどちらの機能も兼ね備えているため、どちらのメンバー変数も使うことができます。
また、どちらの基底クラスへのポインター・参照へも代入できます。

## 7.5.1 多重継承の注意点
多重継承は一見便利なように思えますが、クラスの継承関係をより複雑にするので、使う場面を見極める必要があります。
C++ではインターフェースは提供されていないため、インターフェースの代わりとして多重継承を使用していることがほとんどです。
まずはシンプルな継承で対応するようにして、どうしても難しいような場合のみに多重継承を使うようにすると良いでしょう。

## 7.5.2 多重継承時の基底クラスのコンストラクター呼び出し
多重継承のときの基底クラスのコンストラクターへ引数を渡す方法について。
継承している基底クラスの数だけ対応するコンストラクター呼び出しを列挙する。

```C++
class Derived : public BaseA, public BaseB {
public:
  Derived(int a, int b);
};

Derived::Derived(int a, int b)
 : BaseA{a} // BaseAのコンストラクタを呼び出す
 , BaseB{b} // BaseBのコンストラクタを呼び出す
  {}
```

このとき注意しなければならないのは、列挙する基底クラスのコンストラクター呼び出しのリストは、継承している順番と一致させておいた方が良いということです。
基底クラスのコンストラクター呼び出しは、継承している順番通りにされることになっているため、初期化リストに書いた順番では初期化されないため。
```C++
class BaseA {
public:
  explicit BaseA(int value) : value{value} {
    std::cout << "BaseA::BaseA()" << std::endl;
  }

};

class BaseB {
public:
  explicit BaseB(int value) : value{value} {
    std::cout << "BaseB::BaseB()" << std::endl;
  }
};

class Derived : public BaseA, public BaseB {
public:
  Derived(int a, int b);
};

Derived::Derived(int a, int b)
 : BaseB{b} // BaseBのコンストラクタを呼び出す
 , BaseA{a} // BaseAのコンストラクタを呼び出す
  {}

int main() {
  Derived derived{42, 72};
  derived.show_baseA();
  derived.show_baseB();
  // 出力 継承順であり、初期化リストの順番とは異なる。
  // BaseA::BaseA()
  // BaseB::BaseB()
}
```