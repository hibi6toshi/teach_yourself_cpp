#include <iostream>

void throw_zero() {
  throw 0; // int型の例外オブジェクトを投げる
}

int main() {
  try {
    throw_zero();
  } catch (float f) {
    std::cout << "float型の例外オブジェクトを捕まえました 値 = " << f << std::endl;
  } catch (...) { // どのcatch節にも一致しなかった場合、全ての例外を捕まえることができる
    // ただし例外オブジェクトの値を取得することはできない
    std::cout << "未対応の例外オブジェクトを捕まえました" << std::endl;
  }
  // catch(...)の後にcatch節を置くことはできない
  std::cout << "catch後" << std::endl;
  // 未対応の例外オブジェクトを捕まえました
  // catch後
}