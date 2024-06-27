# 識別子とC++のキーワード

**識別子**とは関数やかた、変数といった名前に相当するもののことです。プログラムを直接構成するそれらの要素は、必ず識別子のルールに従う必要があります。

## 識別子のルール
識別子は、半角英数字と**アンダースコア**(_)の組み合わせからなりますが、数字から始まることはできません。その際、アルファベットの大文字と小文字は区別され、Aとaは異なる識別子として扱われます。

## アンダースコアの扱い
アンダースコアを含む識別子の一部は言語使用で予約されているので、ユーザーが定義することでプログラムがただっしく動作しない場合があります。

言語使用が予約している識別子は次のとおり

- アンダースコアが2つ連続した部分を具組むもの(hoge__fuga)
- アンダースコアで始まり、大文字のアルファベットが少なくとも1つ続くもの(_Foo)
- グローバル名前空間において、アンダースコアで始まるもの(_0)

アンダースコアで始まる識別子は混乱の元なので、避けた方が良い。

## 暗黙的に定義される識別子
C++には、キーワードやそれに類する識別子以外にも、暗黙的に定義される識別子がいくつかあります。これらはプログラムそれ自身に関するメタ情報を文字列や数値で表します。

`__FILE__` : ソースファイル名
`__LINE__` : ソースコード中の__LINE__が出現した位置の行番号
`__func__` : 関数本体に__func__が出現した場合に、その関数名
`__cplusplus` : プログラムがC++としてコンパイルされる場合に、参照しているC++のバージョン