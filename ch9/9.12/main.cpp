#include <iostream>
#include <initializer_list>

// T型の要素を持つコンテナ
template <typename T>
class Container {
  T* ptr = nullptr;
  std::size_t count = 0;

public:
  // countで指定された数、initを使って初期化する
  explicit Container(const T& init, std::size_t count);

  // 初期化リスト{}を使って初期化する
  Container(std::initializer_list<T> init);

  ~Container() { delete [] ptr; }

  void show() const;
};

template <typename T>
Container<T>::Container(const T& init, std::size_t count) : ptr{new T[count]}, count{count} {
  for (std::size_t i = 0; i < count; ++i) {
    ptr[i] = init;
  }
}

template <typename T>
Container<T>::Container(std::initializer_list<T> init) : ptr{new T[init.size()]}, count{init.size()} {
  std::size_t i = 0;
  for (auto& e : init) {
    ptr[i++] = e;
  }
}

template <typename T> 
void Container<T>::show() const {
  for(std::size_t i = 0; i < count; ++i) {
    std::cout << ptr[i] << std::endl;
  }
}

int main() {
  // 本来は Container<std::string> と書くが、コンストラクターの実引数から型推論する
  // 第一引数がテンプレートパラメーターTを使っていて、std::stringが渡されているので、
  // Tはstd::stringに推論される
  Container s{std::string{"hello"}, 3};

  s.show();

  Container i = { 0, 1, 2, 3 }; // 初期化リストから型推論する

  i.show();

  // hello
  // hello
  // hello
  // 0
  // 1
  // 2
  // 3
}