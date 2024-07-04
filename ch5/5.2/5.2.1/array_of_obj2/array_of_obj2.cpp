#include <iostream>

class A {
  std::string m_name;
  int         m_value;

public:
  explicit A(std::string name, int value); 
  explicit A(std::string name);
  A(); // デフォルトコンストラクター
  void show() const;
};

A::A(std::string name, int value)
 : m_name(name), m_value(value) {}

A::A(std::string name) 
 : A(name, -1){}

A::A() : A("default"){};

void A::show() const {
  std::cout << "m_name: " << m_name << " m_value: " << m_value << std::endl;
}

int main() {
  A a[4] = {
    A{"first", 42},
    A{"second"},
    // ３つ目以降はデフォルトコンストラクターが呼ばれる
  };

  a[0].show();
  a[1].show();
  a[2].show();
  a[3].show();
}