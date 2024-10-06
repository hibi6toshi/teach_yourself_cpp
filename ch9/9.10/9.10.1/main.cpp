#include <type_traits>

template<typename T>
class vector2d {
  static_assert(std::is_signed<T>::value, "Tは符号を扱える数値型である必要があります");

  T x;
  T y;

public:
  // ..
};

vector2d<float> vf; // OK
vector2d<int> vi; // OK
vector2d<unsigned int> vu; // コンパイルエラー
// main.cpp: In instantiation of 'class vector2d<unsigned int>':
// main.cpp:16:24:   required from here
// main.cpp:5:36: error: static assertion failed: Tは符号を扱える数値型である必要があります