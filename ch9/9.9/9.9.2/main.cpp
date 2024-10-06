template <typename... T>
void function(T&&... args);

// 引数の数が可変なテンプレート引数
template <typename... T>
void foo(T&&... args) {
  // 引数を全て別の関数に完全転送する
  function(std::forward<T>(args)...);

  // foo<int, float, char>(1, 2.0f, 3) と呼び出された場合、実体化のときに
  // void foo(int args_1, float args_2, char args_3) のようになるので、
  // パラメーターパックが展開されると
  // fuction(std::forward<int>(args_1), std::forward<float>(args_2), std::forward<char>(args_3)); となる
}
