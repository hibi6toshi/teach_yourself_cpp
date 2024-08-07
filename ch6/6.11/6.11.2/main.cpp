class A {
public:
  operator int() const { return 0; }
};

class B {
public:
  // explicit 指定されたint型への変換関数
  explicit operator int() const { return 0; }
};

int main() {
  A a;
  int ia = a; // ok 変換関数はexplicit指定されていない
  char ca = a; // ok int型に暗黙変換された後、charに代入される

  B b;
  // int ib = b; // エラー explicit指定されているので暗黙変換できない
  // char cb = b; // エラー int型への暗黙変換が禁止されているので charに代入できない

  int j(b); // ok 変数jは変換関数の戻り値で初期化される
  int k = static_cast<int>(b); // ok 明示的にキャストした場合は変換関数が呼ばれる
}