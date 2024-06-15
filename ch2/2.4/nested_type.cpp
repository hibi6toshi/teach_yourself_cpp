#include <iostream>

class data{
public:
  using integer = int; // クラスの中で使う整数に別名を与える。

  // クラスの中では別名を直接使える
  integer get_value();
  void set_value(integer new_balue);
private:
  integer value; 
};

// クラスの外ではスコープ解決演算子を使う
data::integer data::get_value(){
  return value;
}


// メンバー関数の中はクラスの内側という扱いなので、
// スコープ解決演算子を使わなくてもネストした型名を使える
void data::set_value(integer new_value) {
  integer tmp = new_value;
  value = tmp;
}

int main() {
  data d;

  // ネストした型名は長くなりがちなので、必要に応じて別名を使う
  using integer = data::integer;

  integer value = 42; // integer は data::integer の別名
  d.set_value(value);
  std::cout << d.get_value() << std::endl;
}
