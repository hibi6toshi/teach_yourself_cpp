# ジェネリックプログラミング
ジェネリックプログラミングとは、プログラムの処理を特定のデータ型に限定しないで記述するプログラミングパラダイム（手法）の一つです。
通常プログラムはint型用の関数はint型のみ扱え、float型用の関数はfloat型のみ扱えるように特定のデータ型と処理とが密接に関連した状態で書かれます。
そのためint型以外の整数型であったり、float型以外の浮動小数点型であったり、他の型でも同じような処理をしたいとなったとしても、型だけが異なる処理を、必要な数だけコピーしてオーバーロードする必要があります。
そのときもし処理の一部を変更しなければならなくなった場合に、たくさん作ったコピーの全てを同じように変更する必要が生じてしまいます。

# 9.1 関数テンプレート
テンプレートの最も基本的な使い方は**関数テンプレート**です。
関数テンプレートは、関数の引数や戻り値をさまざまな型で使えるようにします。機能の名前としては関数テンプレートですが、特定の関数テンプレートを指し示すときには「foo()テンプレート関数」のように呼んだりします。

関数テンプレートの構文は以下の通りです。
```C++
// 関数テンプレートの宣言
template <tyepname template-parameter1, typename template-parameter2...>
return-type function-name(parameters...);

// 関数テンプレートの定義
template <typename template-parameter1, typename template-parameter2...>
return-type function-name(parameters...) {
  function-body...
}
```

templateで始まる行により、続く関数が関数テンプレートであると示しています。そして<と>で囲まれたところに**テンプレートパラメーター**を必要な数だけ記述します。テンプレートパラメーターは関数テンプレートの中だけで使える「型のような何か」で、関数テンプレートの定義の段階では具体的なかたは決まっていません。そのテンプレートパラメーターは戻り値の型の代わりにも使うことができます。

テンプレートパラメーターのリストではtypenameというキーワードを使っていますが、typenameキーワードの代わりにclassキーワードを使うこともできます。typenameキーワードでもclassキーワードでも意味としては全く同じものです。

関数テンプレートを呼び出すには次のようにします。
```C++
// 関数テンプレートの呼び出し
function-name<template-argument1, template-argument2...>(argument...)
```

関数名と実引数の間で<と>を使って具体的な型をテンプレートの引数として渡します。すると、テンプレートパラメーターを使っていた箇所がすべて、指定された方に**置換**されます。全てのテンプレートパラメーターが何かしらの具体的な方に沖川あった段階で、それらの型を使った関数のコピーが作られます。このコピーが作られることを**実体化**といいます。
実体化していない関数テンプレートはまだ具体的な型が決まっていない、つまり具体的な処理が決まっていないので呼び出すことができません。

関数テンプレートでは、呼び出すときに実際に必要な型が決まります。そのため、処理を記述しているときにはそれほど対応漏れを考える必要はありません。
テンプレート引数には好きなかたを渡すことができますが、見境なくなんでも渡せるわけではありません。
テンプレートパラメーターをその型で置換したときに、エラーになるような関数呼び出しなどがあった場合にはそのままエラーとなります。

クラスのメンバー関数であっても関数テンプレートにすることができます。
