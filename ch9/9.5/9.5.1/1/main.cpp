#include <iostream>
#include <vector>

int main() {
  std::vector<int> v{10, 20, 30};

  // ネストした型はとても長くなり、ミスしてしまうかもしれない
  // std::vector<T>::reference は std::vector<T> の参照型(T&)をネストした型名
  // エラー 型を間違えてしまった場合。元々は v はstd::vector<float> だったかもしれない
  // std::vector<float>::reference r = v[0];

  // 添字を使ってアクセスしているため、型を書かなくても要素への参照をしているだろうと考えられる。
  // 添字演算子を使っているから要素への参照を取得しているはずだ、とわかるので
  // autoを使っても型の予想がついて読むときに齟齬があまり生まれない。
  const auto& cr = v[0];
}