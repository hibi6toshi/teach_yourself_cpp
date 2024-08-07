int main() {

  int& a = 1;   // エラー　通常の参照は左辺値のみを受け付ける（右辺値は受け付けない）

  int v;
  int&& b = v; // エラー　右辺値参照は左辺値で初期化できない。
  int && c = b; // エラー　右辺値参照型変数は左辺値なので、右辺値参照型変数を初期化できない。
  int& d = b; // OK 右辺値参照型は参照なので参照を初期化できる。

  // int&& c = 1; // OK 右辺値参照型変数は右辺値を初期化できる。

  a = 10; // OK 参照は左辺値なので右辺値を代入できる。
  b = 10; // OK 右辺値参照は左辺ちんあので右辺値を代入できる。
}