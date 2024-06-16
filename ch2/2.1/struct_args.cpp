#include <iostream>

struct product {
  int id; // 商品ID
  int price; // 価格
  int stock; // 在庫数
};

// 引数として構造体変数を受け取る関数
void show_product(product product) {
  std::cout << "商品ID: " << product.id << std::endl;
  std::cout << "価格: " << product.price << std::endl;
  std::cout << "在庫数: " << product.stock << std::endl;
}

int main() {
  product pen = { 0, 100, 200 };
  show_product(pen);
}