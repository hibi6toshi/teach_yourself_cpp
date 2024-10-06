# 9.8 依存名
## 9.8.1 typenameキーワード
テンプレートは便利な反面とても複雑になりがちです。特にテンプレートの中に出てくる型や変数が、テンプレートパラメーターを使っている場合、**依存**しているといい、それら型名や変数名のことを特に**依存名**といいます。テンプレートは複雑で、依存名が型名なのか変数名なのかがわかりづらいので、型名に関しては特別なキーワードをつけることになっています。

一見するとdot_product関数は、テンプレートパラメーターであるVector内で定義されているvalue_typeという型を返すことを意図しているよに見えます。
しかし、value_typeというのはテンプレート引数によっては型ではなく、staticメンバー変数などを指すかもしれません。
このように、value_typeはテンプレート引数に依存してしまうため、value_typeが「型」であるとコンパイラーに指示するためにtypenameキーワードを使用します。

typenameキーワードは、テンプレートパラメーターのネストした型を直接使っていなくても、「テンプレートパラメーターを使ったテンプレートのメンバー型」など、テンプレートパラメーターに依存していれば必要になります。しかし、必要のない場合にtypenameを使用してもエラーにならないので、不安な場合や、わかりやすくするためにtypenameを使うのは問題ありません。

## 9.8.2 別名
テンプレートパラメーターに依存した型名を使うにはtypenameキーワードが必要ですが、ただでさえテンプレートを使っているだけでも型名が長くなってしまいがちです。**エイリアステンプレート**はテンプレートパラメーターの全部または一部を指定したテンプレートに、別名を付けることができます。

```C++
// エイリアステンプレートの構文
template <template-parameter1, template-parameter2...>
using alias-name = template-expression;
```

## 9.8.3 template限定子
template限定子は、依存名がテンプレートであったときに必要になるtemplateキーワードの用法です。依存名が型名かどうかでtypenameが必要となりましたが、template限定子は依存名がクラステンプレートなのか関数テンプレートなのかに関わらず必要となります。

```C++
// 依存名が関数テンプレートのときの関数呼び出し
dependent-name.template member-name<template-parameters...>(parameters...)

// 上記同様にアロー演算子を使った関数テンプレートの呼び出し
dependent-name->template member-name<template-parameters...>(parameters...)

// 依存名が関数テンプレートなstaticメンバー関数の呼び出し
dependent-name::template member-name<template-parameters...>(parameters...)

// 依存名がテンプレートクラスでクラステンプレートやエイリアス、その他staticメンバー変数等のとき
dependent-name::template memter-name<template-parameters...>
```

いずれの場合でもメンバー名の前に**template**キーワードをつけてメンバー関数の呼び出しや、ホストした型名の取得をします。

