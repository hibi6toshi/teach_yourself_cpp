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