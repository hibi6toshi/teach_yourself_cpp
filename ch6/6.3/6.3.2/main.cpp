#include <iostream>

class Integer {
  int value;

public:
  Integer(int value) : value{value} {}

  Integer& operator++(); // 前置インクリメント
  Integer& operator--(); // 前置デクリメント

  // 後置は第2項にint型を受け取る関数としてオーバーロードする
  Integer operator++(int); // 後置インクリメント
  Integer operator--(int); // 後置デクリメント

  void show() const;
};

Integer& Integer::operator++() {
  // 前置は変更した後の値（自分自身）を返すので、
  // メンバー変数を変更してから自分自身を参照で返す。
  ++value;
  return *this;
}

Integer& Integer::operator--() {
  --value; 
  return *this;
}

Integer Integer::operator++(int) {
  // 後置は変更前の値を返さないといけないので、
  // 先に自分のコピーを作っておく。
  auto tmp = *this;
  ++*this; // 動作に一貫性を持たせるため前置を呼び出す。
  return tmp;
}

Integer Integer::operator--(int) {
  auto tmp = *this;
  --*this;
  return tmp;
}

void Integer::show() const {
  std::cout << "Integer.value = " << value << std::endl;
}

int main() {
  Integer x = 10;

  ++x;
  x.show();

  Integer tmpx = x++;
  x.show();
  tmpx.show();

  --x;
  x.show();

  Integer tmpx2 = x--;
  x.show();
  tmpx2.show();
}