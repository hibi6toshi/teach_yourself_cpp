#include <iostream>
#include <string>


class person {
  std::string m_name;
  int         m_age;
public:
  person();
  ~person(); // デストラクター

  void set_name(std::string name);
  void set_age(int age);

  std::string name() const;
  int         age() const;
};

person::person() : m_age(-1) {
  std::cout << "コンストラクター呼び出し" << std::endl;
}

// personのインスタンスが使われなくなったときに呼ばれるデストラクター
person::~person() {
  std::cout << "デストラクター呼び出し" << std::endl;
}

void person::set_name(std::string name) {
  m_name = name;
} 

void person::set_age(int age) {
  m_age = age;
}

int person::age() const {
  return m_age;
}

std::string person::name() const {
  return m_name;
}

int main() {
  person bob;
  bob.set_name("Bob");
  bob.set_age(20);
  std::cout << "main関数の最後" << std::endl;

  // bobはもう使われないので、デストラクターが呼ばれる
}