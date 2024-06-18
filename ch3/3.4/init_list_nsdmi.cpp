#include <iostream>
#include <string>

class Book {
  std::string title = "";
  int         page = 0;

public:
  Book();
  explicit Book(std::string title, int page);

  void show() const;
};

// pageはメンバー初期化リストで省略したので、NSDMIのデフォルト値で初期化される。
Book::Book() : title("untitled") {}

// メンバー初期化リストで与えた初期値が使われる。
Book::Book(std::string title, int page) : title(title), page(page) {}

void Book::show() const {
  std::cout << title << " " << page << "ページ" << std::endl;
}

int main() {
  Book nsdmi; // NSDMIで初期化される

  nsdmi.show();

  Book old_edition{ "C++ Primer", 1000 }; // NSDMIで初期化される

  old_edition.show();
}