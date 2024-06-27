# 分割コンパイル

## コンパイル
ソースファイルをコンピュータが実行できる形式(**実行形式ファイル**)に変換する手順を**コンパイル**といい、ソースファイルをコンパイルして実行形式ファイルにするプログラムのことを**コンパイラー**といいます。

## プリプロセス
コンパイルの直前には、ヘッダーファイルを読み込んだりマクロ展開などの前処理が実施されます。
この手順のことを**プリプロセス**といいます。そして、プリプロセスを行うためのプログラムを**プリプロセッサー**といいます。

## リンクとビルド
複数のソースファイルから１つのプログラムを作り上げる手順のことを**ビルド**といいます。
コンパイルはソースファイルを実行形式ファイルにすることでしたが、正確にはコンパイルだけでは実行可能なファイルは出来上がりません。
コンパイルによって作られるファイルはオブジェクトファイルと呼ばれ、それ単体ではプログラムは実行できないからです。ビルドではそれぞれのソースファイルをコンパイルし、ソースファイルの数だけオブジェクトファイルを作った後に、それらを全て結合して実行形式ファイルを作り上げます。
その最後の手順のことを**リンク**といい、リンクするためのプログラムのことを**リンカー**といいます。

ソースファイルを複数に分割してプログラムを組むときには、お互いにどんな関数やクラスを持っているのか、関数宣言やクラス定義だけを集めたヘッダーファイルを用意し、その宣言や定義が必要になったソースファイルでインクルードします。

```C++: module.hpp
// ヘッダーファイルに必要なのは関数宣言のみ
void show_value(int value);
```

```C++: module.cpp
// このソースファイルで使う宣言が含まれるためインクルードする
#include "module.hpp"

#include <iostream>

void show_value(int value) {
  std::cout << "value = " << value << std::endl;
}
```

```C++: main.cpp
// 前方宣言を取り込む
#include "module.cpp"

int main() {
  show_value(42);
}
```

## extern変数
ヘッダーファイルや複数のソースファイルでグローバル変数を宣言してしまうと、それぞれのソースファイルがコンパイルされたときに、それぞれのオブジェクトファイルがグローバル変数の実態を持つようになってしまいます。
コンパイラーは定義を見つけるとその度に実体を作ってしまうのですが、リンクの際にグク数の実態があるとどれが本物か区別をつけることができません。グローバル変数の実態は特定のソースファイルだけで定義して、その他のソースファイルやヘッダーファイルでは定義されないようにする必要があります。

変数宣言の際に**externキーワード**を使うと、コンパイラーが「そのグローバル変数の実態はどこか別のところで定義される」ものとして扱うため、変数の実態を作らなくなります。そのようなexternキーワードが付いた変数のことを**extern変数**と呼びます。

extern変数はグローバルスコープの変数でしか宣言できません。ファイルスコープの（staticな）グローバル変数はそのソースファイルでしか使えないため、externキーワードを使っても他のソースから使うことはできません。

```C++
extern type-name variable-name;
```

extern変数は「変数が存在していること」の宣言しかしていないため、初期値を与えることはできません。
初期値は「externキーワードをつけずに変数宣言している箇所」で与える必要があります。

## staticメンバー変数の定義
staticメンバー変数だけはクラス定義時の宣言だけでは不十分で、クラス定義の外側で別途定義が必要でした。もしstaticメンバー変数の定義をヘッダーファイルに書いてしまうと、ソースファイルごとに定義が行われてしまい、やはりリンク時に本物の実態がわからなくなってしまうため、staticメンバー変数の実態もどこか１つのソースファイルでのみ定義する必要があります。