# 9.7 参照の推論と完全転送
## 9.7.1 参照渡し
関数テンプレートで参照渡しをする場合、テンプレートパラメーターの使い方によって２通りの書き方があります。
1つ目はテンプレートパラメーター自体を参照型にする方法です。これは型推論をさせる場合には使えませんが、環数呼び出しのときにテンプレート引数として参照型を指定する方法です。

```C++
template <typename>
void foo(T variable) {
  ...
}

int i = 0;

// テンプレート引数Tをint&にして呼び出し
// Tをそのままint&に置き換えた void foo(int& variable) という関数を呼び出す
foo<int&>(i);
```

2つ目はテンプレートパラメーターに&を付けた型で仮引数を宣言する方法です。これは常に参照渡しになるようにテンプレートが実体化されます。
```C++ 
template <typename T>
void foo(T& variable) {
  ...
}

int i = 0;

// テンプレートパラメーターTをintにしても、
// 関数テンプレートの宣言に&が付いているので必ず参照渡しになる。
foo<int>(i); // void foo(int& variable)

// 型推論を使っても参照渡しとなる
// テンプレートパラメーターTはint型に推論される
foo(i); // void foo(int& variable)
```

参照だけでなくconstについても参照と同じ規則で型推論されます。そしてそれらを組み合わせた、常にconstで参照を受け取る関数テンプレートというのがよく使われます。
```C++
// 常に引数をconst参照で受け取るテンプレート
template  <typename T>
void foo(cont T& variable) {
  ...
}
```

## 9.7.2 フォワーディング参照
**フォワーディング参照**は右辺値参照とテンプレートを組み合わせたときに特別な動作をする参照のことです。テンプレートではない関数では右辺値参照に左辺値を渡すことはできませんが、テンプレート引数を使った右辺値参照を関数テンプレートの仮引数として使うと、右辺値だけでなく左辺値も受け取ることができるテンプレートとして動作します。

```C++
// 右辺値参照で受け取る関数テンプレートを定義したつもりだが
template<typename T>
void foo(T&& value) {
  ...
}

int i = 0;

foo(i); // OK 左辺値を渡すことができる

foo<int&>(i); // OK 参照型のテンプレート引数を明示的に渡すこともできる

foo(0); // OK 右辺値を渡すことができる

const int j = 0;

foo(j); // OK constな変数を渡すとconst参照として呼び出される

foo<const int&>(j); // OK const参照もテンプレート引数に明示的に渡すことができる
```

このとき、それぞれの呼び出しでテンプレート引数Tが推論される型は、左辺値の場合にはそれぞれの参照型、右辺値の場合には非参照型となります。

```C++
foo(i); // T => int&

foo(0); // T => int

foo(j); // T => const int&
```

constをつけるとフォワーディング参照ではなくconstな右辺値参照となってしまい、左辺値を渡せません。

```C++
template <typename T>
void foo(cont T&& value); // フォワーディング参照ではなくconstな右辺値参照

int i=0;

foo(i); // エラー　フォワーディング参照ではないので左辺値を渡すことができない
```
フォワーディング参照は左辺値にもマッチしてしまうので、時として意図していないオーバーロード呼び出しとなってしまう可能性があります。
そういった場合には、左辺値を受け取る関数テンプレートを別途用意しておくことで、消去法で右辺値でのみ呼ばれる関数テンプレートとなります。

## 9.7.3 完全転送
**完全転送**とは、フォワーディング参照と組み合わせて使われるテクニックのことです。
右辺値参照型の変数は左辺値であった。
フォワーディング参照を使った右辺値参照となった場合でも、その規則は変わることはなくその仮引数は左辺値として扱われます。
つまりフォワーディング参照を使った場合、仮引数はどのような場合でも左辺値となるので、再度その仮引数を右辺値もしくは左辺値として別の関数に渡したい場合、そのままでは元々の実引数がどちらであったかが区別できません。

<utility>ヘッダーで定義されているstd::forward()関数を使うとフォワーディング参照の仮引数を上手に区別して関数を呼び出すことができます。
完全転送とは、std::forward()関数を使った右辺値と左辺値を区別した関数呼び出しのことをいいます。

std::forwardは関数テンプレートとなっていて、そのテンプレートパラメーターには呼び分けたいフォワーディング参照の仮引数に使ったテンプレートパラメーターを指定します。