# 初期化構文付き条件分岐

## 初期化構造付きif文
条件分岐では、関数などが返す返り値を条件の一部として使って分岐することが多くあります。
初期化構文付きif文を使うと、これを2行に分けて行うのではなく条件分岐の１行だけで済ませることができます。
```C++
if (type-name variable-name = expr; condition) {
  if-stmt-body...
} else {
  else-stmt-body...
}
```
初期化構文付きif文は、次のような通常のif文と同じ意味になります。
```C++
{
  type-name variable-name = expr;
  if (condition) {
    if-stmt-body...
  } else {
    else-stmt-body...
  }
}
```
