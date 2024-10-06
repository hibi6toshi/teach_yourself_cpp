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

## 9.9.2 さまざまなパラメーターパックの展開
展開の際にパラメーターパックの全ての要素に関すや演算を適用することもできます。
受け取った引数をさらに別の可変引数テンプレートへ渡したりする際に、必ずといってよいほど使われる機能です。

```C++
template <typename... T>
void function(T&&... args);

// 引数の数が可変なテンプレート引数
template <typename... T>
void foo(T&&... args) {
  // 引数を全て別の関数に完全転送する
  function(std::forward<T>(args)...);

  // foo<int, float, char>(1, 2.0f, 3) と呼び出された場合、実体化のときに
  // void foo(int args_1, float args_2, char args_3) のようになるので、
  // パラメーターパックが展開されると
  // fuction(std::forward<int>(args_1), std::forward<float>(args_2), std::forward<char>(args_3)); となる
}
```
注意するのは、完全転送の際にテンプレートパラメーターパックと関数パラメーターパックの両方を指定している点です。

```C++
X<T...>(t...) // X<T0, T1, ...>(t0, t1, ...) と展開される
X<T...>(t)... // X<T0, T1, ...>(t0), X<T0, T1, ...>(t1), ... と展開される
X<T>(t...) // X<T0>(t0, t1, ...), X<T1>(t0, t1, ...), ... と展開される
X<T>(t)... // X<T0>(t0), X<T1>(t1), ... と展開される
```
## 9.9.3 テンプレートパラメーターパックの要素数
テンプレートパラメーターパックの要素数を取得するにはszieof... 演算時を使います。
```C++
sizeof...(parameter-pack)

// もし...の位置を間違えて sizeof(T...) や sizeof(T)... としてしまうとパラメーターパックの展開になってしまいます。
```
パラメーターの個数がわかると、それを元に処理を変更したりエラーにすることができたりもします。
