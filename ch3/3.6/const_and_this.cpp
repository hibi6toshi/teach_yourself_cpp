class A {
  int value;

public:
  void set_value(int value);
  int get_value() const;
  int get_value2() const;
};

void A::set_value(int value) {
  this->value = value;
}

int A::get_value() const {
  return value;
}

int A::get_value2() const {
    // this->value = 0; // これはエラーになる thisはconst A*型なので、メンバー変数を変更できない
    // this->set_value(0); // エラー　const修飾していないメンバー関数を呼び出している
  // OK this->get_value(); // const修飾しているメンバー関数を呼び出している
  return this->get_value(); // OK
}