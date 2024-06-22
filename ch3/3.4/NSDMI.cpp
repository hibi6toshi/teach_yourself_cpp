#include <iostream>

class S {
public:
  int answer = 42; // NSDMI
  float pi{ 3.14159f }; // NSDMI
};

struct T {
  std::string title = "C++"; // NSDMI
  int version{ 2017 }; // NSDMI
};

int main() {
  S s;

  std::cout << "s.answer: " << s.answer << std::endl;
  std::cout << "s.pi: " << s.pi << std::endl;

  T t;

  std::cout << "t.title: " << t.title << std::endl;
  std::cout << "t.version: " << t.version << std::endl;
}