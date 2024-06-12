int main() {
  // 変数宣言
  int a; 

  // カンマ区切りで複数の変数を宣言
  int b, c;

  // 変数の初期化
  // 宣言された直後には、どんな値が入っているかは`決まっていない`
  // そのため、変数の初期化(initialization)を行う。
  // 初期化とは、変数に初期値を設定することである。
  // 例えば、int型の変数aに10を代入する場合、以下のように記述する。
  int a(0);
  int b = 1;
  int c{2};
  int d = {3};

  // 変数を同時に複数宣言して、初期化することもできる。
  int e = 4, f, g = 6; // fは初期化されていない

  // 定数の宣言
  const int h = 7;
  int const i = 8; // constは型の前でも後ろでもよい
}