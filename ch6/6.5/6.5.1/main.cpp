#include <iostream>

class Integer {
  int value;

public:
  Integer(int value) : value{value} {}

  bool operator==(const Integer& rhs) const;
  bool operator!=(const Integer& rhs) const;

  bool operator<(const Integer& rhs) const;
  bool operator>(const Integer& rhs) const;
  bool operator<=(const Integer& rhs) const;
  bool operator>=(const Integer& rhs) const;
};

bool Integer::operator==(const Integer& rhs) const {
  return value == rhs.value;
}

bool Integer::operator!=(const Integer& rhs) const {
  // == を呼び出して判定する
  return !(*this == rhs);
}

bool Integer::operator<(const Integer& rhs) const {
  return value < rhs.value;
}

bool Integer::operator>(const Integer& rhs) const {
  // 左右を入れ替えて < を呼び出す
  return rhs < *this;
}

bool Integer::operator<=(const Integer& rhs) const {
  // 大なりを呼び出して否定する
  return !(rhs < *this);
}

bool Integer::operator>=(const Integer& rhs) const {
  // 左右を入れ替えて <= を呼び出す
  return rhs <= *this;
}

int main() {
  Integer x = 10;
  Integer y = 3;

  if (x != y) {
    std::cout << "x != y はtrue" << std::endl;
  } else {
    std::cout << "x != y はfalse" << std::endl;
  }

  if (y >= x) {
    std::cout << "y >= x はture" << std::endl;
  } else {
    std::cout << "y >= x はfalse" << std::endl;
  }
}