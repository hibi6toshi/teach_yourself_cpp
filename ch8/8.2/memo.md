# 8.2 書式設定された出力
これまで、何かしらの値を出力するときには標準ライブラリがデフォルトで提供していたフォーマットが常に使われていました。
標準ライブラリによる出力にはよく使われる書式に関して、ユーザーがわざわざ整形しなくても表示できるような機能が提供されています。

## 8.2.1 std::ios::fmtflagsフラグ
単に表示の方お方を変えるだけのものであれば、入出力オブジェクトに対してフラグを設定することで簡単に切り替えることができます。

フラグの取得・セット・アンセット
```C++
std::ios::fmtflags flags() const;

std::ios::fmtflags setf(std::ios::fmtflags fmtfl);

void             unsetf(std::ios::fmrflags fmtfl);
```

flags()メンバー関数とseft()メンバー関数にはそれぞれオーバーロードが存在します。

flags関数とself関数のオーバーロード
```C++
std::ios::fmtflags flags(std::iosfmtflags fmtfl);

std::ios::fmtflags setf(std::ios::fmtflags fmtfl, std::ios::fmtflags mask);
```

## 8.2.2 さらに柔軟な書式設定
引数を与えることで、幅（桁）・精度・充填文字は柔軟に書式を設定できるものがあります。

```C++
// 幅・精度・充填文字
std::streamsize width() const;
std::streamsize width(std::streamsize wide);

std::streamsize precision() const;
std::streamsize precision(std::streamsize prec);

char            fill() const;
char            fill(char ch);
```

widthは出力幅を設定するために使う。
precisionは浮動小数点の精度に影響する。
fillは充填文字を設定する。

widthに関しては使用するたびに設定しておくのが良い。（いくつかの出力はwidth(0)を呼び出してしまうから）