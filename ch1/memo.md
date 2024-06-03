# 1.1 Hello world

## ヘッダーファイルの読み込み

#include 命令を使ってヘッダーファイルを読み込む。何か機能を使いたい場合にはあらかじめその機能について書かれた **ヘッダーファイル**を読み込ませる必要があります。

##  main()関数　
C++ではmain()という名前を持った関数を特別な関数としており、最初に実行することになっています。関数は開き**ブレース**( { : brace ) で始まり、閉じブレース(})で終わります。

## コメント
`//` : その量の終わりまでコメントアウト
`/* */`: 囲まれた部分だけがコメントになる。

# 1.2 変数と関数
変数宣言の構文は次の通り

```
type-name variable-name;
```

複数変数の同時宣言
```
type-name variable-name1, variable-name2;
```

変数宣言と同時に初期化を行うには、以下のような構文を使います。
```
type-name variable-name(initial-value);

type-name variable-name = initial-value;

type-name variable-name{initial-value};

type-name variable-name = {initial-value};
```

## const 修飾子
あとから代入できない変数を作るには、変数宣言の時に `const 修飾子`をつけます。 const修飾子がついた変数このとを一般に`const 変数`と呼びます。
```
const type-name variable-name = initial-value;

type-name const variable-name = initial-value;
```

const 変数は後から代入できないため、const変数は初期化を省略するとエラーになります。
