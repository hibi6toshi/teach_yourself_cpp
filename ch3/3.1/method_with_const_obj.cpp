#include <iostream>

class product {
  int id; // 商品ID

public:
  int get_id();            // 商品IDのgetter
  void set_id(int new_id); // 商品IDのsetter
};

// getterは何も変更しない
int product::get_id() {
  return id;
}

// setterはメンバー変数を変更する
void product::set_id(int new_id){
  id = new_id;
}

int main() {
  product p;
  p.set_id(42);
  std::cout << p.get_id() << std::endl; //  問題なし

  const product cp{}; // constオブジェクトを作成

  // cp.set_id(42); // エラー: constオブジェクトのメンバー変数を変更しようとしている
  
  // std::cout << cp.get_id() << std::endl;  // エラー　しかし、get_id はメンバー変数を変更しないので、問題なしであってほしい
}