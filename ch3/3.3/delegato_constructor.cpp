#include <iostream>
#include <string>

class person {
  std::string m_name;
  int         m_age;

  person(int age);

public:
  person();
  person(std::string name, int age);

  void set_name(std::string name);
  void set_age(int age);

  std::string name() const;
  int         age() const;
};

// 共通な初期化処理がが書かれたコンストラクター
person::person(int age) : m_age(age) {
  // 複数のコンストラクターで共通な大元の処理をprivateなコンストラクターに用意し、
  // 委譲コンストラクターを使うことで、一貫した初期化処理を行うことができる。
  std::cout << "共通コンストラクター呼び出し" << std::endl;
}

// 委譲元コンストラクター（引数なし）
person::person() 
  : person(-1) {
    std::cout << "引数なしコンストラクターの呼び出し" << std::endl;
}

// 移譲元コンストラクター（名前と年齢を引数に取る
person::person(std::string name, int age)
  : person(age) {
    std::cout << "引数付きコンストラクターの呼び出し" << std::endl;

    // 初期化中にメンバー関数を呼び出すこともできる
    set_name(name);
};

void person::set_name(std::string name){
  m_name = name;
}

void person::set_age(int age){
  m_age = age;
}

std::string person::name() const {
  return m_name;
}

int person::age() const {
  return m_age;
}

int main() {
  // 引数を渡して初期化
  person alice("alice", 20);
  std::cout << "名前: " << alice.name() << std::endl;
}