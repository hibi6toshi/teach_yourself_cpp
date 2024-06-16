int main() {
  const int constant = 42; // 変数それ自体が変更不可能
  const int& ref_const = constant; // constな変数への参照
  // int& ref = constant; // エラー: constな変数への非constな参照

  // constant = 0; // エラー: constな変数の値を変更しようとしている
  // ref_const = 0; // エラー: constな変数への参照を使って値を変更しようとしている

  int value = 72; // 変数はconstではない
  int& reference =  value; // 通常の参照
  const int& con_reference = value; // constな参照

  value = 0; // OK : value は変更可能
  reference = 0; // OK : reference は value への参照なので value の値が変更される
  // con_reference = 0; // エラー: constな参照を使って値を変更しようとしている
}