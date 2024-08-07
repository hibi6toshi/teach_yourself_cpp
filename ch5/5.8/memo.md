# 5.8 右辺値参照
変数・引数・数値といったなにかの「値」は、大きく分けると**左辺値**と**右辺値**という2つに分類されます。
このうち変数や引数は左辺値と呼ばれ、値を代入することができるものを指します。
一方、数値リテラルは右辺値と呼ばれ、値を代入することはできません。

## 5.8.1 通常の参照と右辺値参照
通常の参照は左辺値でのみ初期化でき、右辺値ではできません。
**右辺値参照**はそのような通常の参照とは少し異なり、右辺値への参照のみを格納できる機能です。

```C++
type&& variable = R-value; 
```

右辺値参照は右辺値でのみ初期化でき、左辺値では初期化できない。
右辺値参照型の変数は左辺値です。参照は他の参照変数を参照できますが、右辺値参照は他の右辺値参照型変数を参照することはできません。

## 5.8.2 右辺値のアドレス
右辺値参照には右辺値を参照できるだけでなく、値を代入することができます。しかし右辺値自体に代入することはできないはずなので、参照とはいえ奇妙に感じるかもしれません。

```C++
int&& i = 1; // 1への右辺値参照
i = 0; //OK iは左辺値
if (1 == 0) { // 1 == 0 となってしまったのか？

}
```
左辺値の場合、オブジェクトが同じものであるかを調べるにはアドレス値を使って確認しました。
右辺値はどのようなアドレス値を持っているのでしょうか？
実は右辺値のアドレスを取ろうとするとエラーになります。このエラーは、右辺値が有効なアドレスを持っていないことを表しています。
```C++
int* p = &0; // エラー　右辺値のアドレスは取れない。
```

右辺値参照型変数は左辺値なので、何かしらの値を持つはず。
-> それぞれの右辺値参照型変数は違うアドレス値をもつ。

## 5.8.3 右辺値参照のオーバーロード
右辺値参照は通常の参照とは異なり、オーバーロードすることができます。
-> 通常の参照用の関数とは別に、右辺参照型用の関数をオーバーロードできる。（内部的には別にしてくれる。）
右辺値の場合に高速に勝利をすることができることがあるので、右辺値参照でオーバーロードすることで効率の良いプログラムをかけることがあります。

## 5.8.4 ムーブコンストラクター
クラスはコピーコンストラクターを定義して、インスタンスがコピーされるときの動作を定義できました。
似たようなコンストラクターとして、**ムーブコンストラクター**というものを定義できます。
コピーコンストラクターはconst参照を受け取っていたのに対して、ムーブコンストラクターは右辺値参照を受け取るコンストラクターです。
コピーコンストラクターとムーブコンストラクターは同一クラス上で両者を定義することができますし、どちらかだけにすることもできます。
```C++
class class-name {
  public:
   class-name(class-name&& variable-name); // ムーブコンストラクター
}
```
std::move()関数(<utiilty>ヘッダーが必要)は左辺値を強制的に右辺値として扱えるようにするヘルパー関数です。

## 5.8.5 コピーとムーブ
コピーコンストラクターとムーブコンストラクターは、どちらも他のインスタンスをもとに初期化するためのコンストラクターですが、その役割には明確な違いがあります。
**コピー(copy)**は文字通り複製という意味で、元のインスタンスとメンバー変数が同じになるように初期化します。ただしメンバー変数が動的確保したポインターを持っていた場合、多重開放しないように、新たにメモリ領域を動的に確保して変数をコピーするのが一般的です。
ただし、メモリーの動的確保はパフォーマンスにとても重大な影響を及ぼすことがあり、コピーをかず多く行うと、プログラム全体の処理が非常に遅くなってしまうことがあります。

一方、**ムーブ(move)**では、コピーと異なり**所有権の移動(ownership transfer)**を行います。コンストラクターで動的確保されたメモリ領域はデストラクターで破棄されるため、オブジェクトの一部とみなすことができますが、実際にはインスタンスとは別のメモリ領域に置かれているものであり、インスタンスの破棄とは直接的には関係しません。そのためインスタンスの一部というよりも、インスタンスがそのメモリ領域を**所有している**と考えることができます。所有権の移動とは、その「所有しているメモリ領域」を他のインスタンスに譲与するという考え方だといえます。

所有権の移動を含む一連の動作あは**ムーブセマンティクス**とも呼ばれ、標準ライブラリはそのほとんどが対応しています。
ムーブセマンティクスはインスタンスを値で受け取る関数の呼び出しでよく見かけます。引数として渡しているインスタンスを関数から戻ってきた後では使わない場合、引数として渡す際にムーブスつろ、コピーしないで関数にインスタンスを渡すことができます。
