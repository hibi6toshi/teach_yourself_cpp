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
