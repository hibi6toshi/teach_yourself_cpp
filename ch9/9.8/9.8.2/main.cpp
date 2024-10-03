#include <vector>

// エイリアステンプレート
template <typename T>
// この型はTに依存しているのでtypenameが必要
using vector_reference = typename std::vector<T>::reference;

template <typename T>
vector_reference<T> // Tを使っているが、エイリアスの中で依存名が解決されているのでここでは不要
at(std::vector<T>& v, std::size_t i) {
  return v[i];
}