# 9.9 可変引数テンプレート
C言語では可変引数を使えるが、C++では可変引数はできるだけ使わずに**可変引数テンプレート**という機能を使う。
可変引数テンプレートはテンプレートなので、個別の引数の型や引数の数を正しく扱えますし、参照で受け取れるので余計なコピーの心配をする必要がありません。

```C++
tepmlate <typename... template-parameter-pack>
return-type function-name(tempalte-parameter-pack... function-parameter-pack);

template <typenma... template-parameter-pack>
return-type function-name(template-parameter-pack... function-parameter-pack) {
  funciton-body...
}

template <typename... template-parameter-pack> 
class class-name;

template <typename... template-parameter-pack>
class class-name {
  class-body...
};
```
ピリオドを3つ打つそれが可変引数テンプレートの意味となる。

## 9.9.1 テンプレートパラメーターパックと展開
可変引数テンプレートで使うテンプレートパラメーターや、そのテンプレートパラメーターを使った仮引数のことをそれぞれ**テンプレートパラメーターパック**や**関数パラメーターパック**と呼んで、これまで扱ってきたテンプレートパラメーターや仮引数と区別します。

複数のテンプレートパラメーターが1つのテンプレートパラメーターパックに収まるため、テンプレートパラメーターパックの変数を作ることはできません。
また、関数パラメーターパックも複数の引数羽を1つのパラメーターパックとして扱うため、変数のように直接操作できません。パラメーターパックの要素を使うには**展開**をしなければなりません。

展開の構文は可変引数テンプレートの構文中に見られるパラメーターパックの宣言と似ていて、ピリオド3つを使います。

展開は全ての要素をカンマ区切りのリストに置き換えるような操作であり、特定の要素にアクセスする**抽出**ではないことに注意しなければなりません。
