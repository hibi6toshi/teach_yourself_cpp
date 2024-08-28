#include <iostream>
#include <fstream>

int main() {
  // 読み込みのみのファイルを書き込みでオープンしようとしている
  std::ofstream of{"read_only.txt"};

  if (of.is_open()) { // ファイルオブジェクトが実際にオープンできたのかを確かめる
    std::cout << "オープン成功" << std::endl;
  } else {
    std::cout << "オープン失敗" << std::endl;
  }
}