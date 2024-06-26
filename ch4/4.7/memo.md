# 名前空間

## 4.7.1 名前空間とスコープ解決演算子
関数や変数、クラスなどは自由に名前をつけることができますが、オーバーロードなどの一部を除き、すでにある名前を別のものにつけることはできません。
例えば次のプログラムはエラーになります。

```C++
using awesom_name = int;

class awesome_name // エラー。awesome_name はすでに使われている
{
  ...
}

int awesome_name; // エラー　クラス名とは衝突しないが、int の別名と衝突する

void awesome_name() // エラー　クラス名とは衝突しないが変数名とintの別名と衝突する
{
  ...
}
```

**名前空間**を使うことで、ライブラリAの関数FとライブラリBの関数Fを区別できるようになります。
例えば、標準ライブラリで定義されるものはすべてstd名前空間の中で定義されているので、同じ名前のクラスなどを定義しても衝突しません。

名前空間の構文は次のとおり
```C++
namespace namespace-name {
  namespace-body...
}
```
namespace-body には関数やクラス、変数や型の別名などおよそほとんどのものを記載でき、それらはすべてnamespace-nameで指定した名前変数に属することになります。

## スコープ解決演算子
ある名前空間にある関数やクラスなどを使いたい場合には、**スコープ解決演算子（::）**を使って、所属する名前空間を一緒に指定する必要があります。
グローバル名前空間のものを使うときには特に名前空間を指定する必要はありません。

スコープ解決演算子の構文は次のとおりです。
```C++
namespace-name::type-name variable-name; // 変数宣言

namespace-name::function-name(); // 関数呼び出し

namespace-name::variable-name; // 変数の使用
```

## 4.7.2 ネストした名前空間
名前空間はその中にさらに名前空間を持つことができます。このようなネストした名前空間を使うと、ライブラリの中でさらに機能ごとに分けたり、ユーザーに公開する日つおようのない内部実装用の機能をまとめたりして、必要な機能だけを整理して提供できます。

```C++
namespace library {
  namespace module {
    namespace detail {
      void internal_function();
    }
  }
}

int main() {
  // ネストした名前空間の内側の関数呼び出し
  library::module::detail::internal_function();
}
```

ネストが深くなると上記のように{}が多くなってしまい、管理が煩雑になります。そこで、名前空間の中に名前空間しかない単純な場合に限り、省略した方法でネストした名前空間を定義できます。
```C++
namespace toplevel-namespace-name::nested-namespace-name {
  ...
}

// 何弾もかける
namespace top-level::midle-name::last_level {
  ...
}
```

