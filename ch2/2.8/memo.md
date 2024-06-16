# ラムダ式
**ラムダ式**(lambda expression)とは、関数を必要に応じてその場で定義する構文です。
**述語**(predicate) を必要とするアルゴリズムや、**コールバック関数**(callback function)を登録するような場合にとても強力な機能です。

## ラムダ式の基本
```
[](parameters...) -> return-type {
  lambda-body...
};
```
ほとんどの場合、関数の実引数、もしくはautoで宣言した変数に代入して使います。

ラムダ式自体は関数のように振る舞う特別なオブジェクト（C++において、lambda式（ラムダ式）自体の型は、**クロージャ型（closure type）**です。）であり、それを変数に大隠喩するため、その関数自体も関数のように呼び出すことができます。

### ラムダ式と auto
ラムダ式はそれぞれコンパイラーが自動で作ったユニークな(一意)の型を持ったオブジェクトとなります。そのためint やfloatといった型を書くことができず、常にautoを使う必要があります。
このp「ユニークな」というのは、例え内容が全く同じラムダ式であっても別の型として扱われるということ意味です。
例えば次のように型推論を使って方を取得したとしても、別のラムダ式を代入することはできません。

```C++
int main() {
  auto a = []() -> int { return 42; };

  // エラー 例え内容が全く同じでも別の方を持つ
  decltype(a) b = []() -> int { return 42; };
}
```

## 戻り値の型の省略
ほとんどの場合、ラムダ式では戻り値の型を省略することができます。その際、コンパイラーがラムダ式の中身から戻り値の型を推論します。ラムダ式がreturn文を使って何か戻り値を返した場合には、その戻り値から型を推論し、「reutrnがない」もしくは「戻り値のないreturnである」場合にはvoidに推論します。
```C++
int main() {
  auto return_void = []() { // []() -> void { と同じ
    std::cout << "何も返さないラムダ式" << std::endl;
  };

  auto return_int = []{} -> { // []() -> int {　と同じ 
    return 42;
  };
}
```

ただし、この推論も常位行こうというわけではない。複数のreturn文があり、1つでも型が異なるreturn 文があった場合にはエラーになります。
```C++
int main() {
  // エラー returnの型が全て同じではない
  auto rectified_linear_unit = [](float x) {
    if (0 <= x) {
      return 0; // int 型
    }

    return x; // float 型
  };
}
```

こういった場合にはreturn文の型を合わせるか、戻り値の型を明記して暗黙の型変換をさせる必要があります。
```C++
int main() {
  auto rectified_linear_unit1 = [](float x) {
    if (0 <= x) {
      return 0.0f; // float型
    }
    return x; // float型
  };

  auto rectified_linear_unit2 = [](float x) -> float { // OK
    if (0 <= x) {
      return 0; // int -> floatへの暗黙的型変換が行われる。
    }

    return x; // float型
  } 
}
```

## 変数のコピーキャプチャ
ラムダ式は、**クロージャ**(閉包: closure)と呼ばれることもあります。これは、ラムダ式の機能である変数の**キャプチャ**(capture) に由来します。
ラムダいsきは単に関数をその場で定義するだけではなく、ラムダ式を定義した時点で有効な変数を取り込んで使うことができます。
通常の関数では、引数でない他の関数の変数を使うことはできません。それはラムダ式においても同じで絵あり、ラムダ式本体というのは全く別の関数という扱いになっているからです。
```C++
#include <iostream>

void callee();

int main() {
  int a = 0;
  callee();

  auto lambda = []() {
    // エラー: 'a' was not captured for this lambda function
    std::cout << a << std::endl;
  };
  lambda();
}

void callee() {
  // エラー: 'a' was not declared in this scope
  std::cout << a << endl;
}
```

ラムダ式は**キャプチャ**という機能を使うことで、ラムダの外側で宣言されている変数のコピーを格納して、ラムダ式の内側で使えるようになります。キャプチャは引数として受け取るのとは異なり、ラムダ式を呼び出す際には必要ありません。
```
[variable, variable...](parameters...) -> return-type { 
  lambda-body...
}

[=, variable, variable...](parameters...) -> return-type {
  lambda-body...
}
```

ラムダ式の先頭に使っていた記号[]はこのためにあった。
ラムダ式内部でも使いたい変数をvariableに列挙することで、コンパイラーが自動でそれら変数をコピーします。

キャプチャしたい変数が多い場合にはデフォルトのキャプチャが使えます。キャプチャの先頭に = を加えることで、ラムダ式内部で使っている変数をコンパイラーが自動的にキャプチャします。