#include <iostream>

struct product {
  int id; // 商品ID
  int price; // 価格
  int stock; // 在庫数
};

int main() {
  product pen; // ペンに関するデータを保つ変数 
  
  // ドット演算子を使ってペンに関する情報をメンバー変数に格納する
  pen.id = 0;
  pen.price = 100;
  pen.stock = 200;

  product* ptr = &pen;
  
  // アロー演算子を使ってメンバー変数を取得する。
  std::cout << "商品ID: " << ptr->id << std::endl;
  std::cout << "価格: " << ptr->price << std::endl;
  std::cout << "在庫数: " << ptr->stock << std::endl;
}