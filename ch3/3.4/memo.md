# デフォルトの初期値

## メンバー変数の初期値
メンバー変数のデフォルト値を指定するには次の構文を使います。
この構文は**非静的メンバー変数の初期化(NSDMI)**という名前があります。
```C++
class class-name {
  type-name variable-anme = default-value;
  type-name variable-name = { default-value };
  type-name variable-name(default-value);
  type-name variable-name{default-value};
};
```

構造体にも同様にNSDMIが使える。

## メンバー初期化リストと初期値
NSDMIを使うとメンバー変数のデフォルト値を指定できましたが、一方でコンストラクターのメンバー初期化リストでもメンバー変数に初期値を与えることができました。両方が使われていた場合、コンストラクターで指定した初期値の方を使って初期化されます。
メンバー初期化リストで初期値が省略された場合にはNSDMIのデフォルト値が使われます。
