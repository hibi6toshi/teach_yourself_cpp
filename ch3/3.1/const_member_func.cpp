#include <iostream>

class product {
  int id; // 商品ID

public:
  int get_id() const;      // 商品IDのgetter
  void set_id(int new_id); // 商品IDのsetter
}; 

// getter は constメンバー関数にする
int  product::get_id() const {
  // id = 1; // エラー: constメンバー関数内でメンバー変数を変更しようとしている
  return id;
}

// setterはメンバー変数を変更するのでconstメンバー関数にはしない
void product::set_id(int new_id) {
  id = new_id;
}


int main() {
  const product p{};

  // OK constメンバー関数はconstなインスタンスに対して呼び出せる
  std::cout << p.get_id() << std::endl;
}