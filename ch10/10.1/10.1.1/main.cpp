#include <iostream>

void throw_zero() {
  std::cout << "例外を投げる前" << std::endl;

  // int型のオブジェクトを例外オブジェクトとして投げる
  // try ブロックがなくても例外を投げることはできる
  throw 0; 

  std::cout << "例外を投げた後" << std::endl;
}

int main() {
  // tryブロックの中で投げられた例外はcatch説で捕まえるか、
  // さらにこの関数の呼び出し元が捕まえる。
  try {
    std::cout << "関数呼び出し前" << std::endl;
    throw_zero();
    std::cout << "関数呼び出し後" << std::endl;
  } catch (int e) { // 例外オブジェクトをここで捕まえる
    std::cout << "投げられた例外オブジェクトは " << e << " です" << std::endl;
  }
  std::cout << "捕まえた後" << std::endl;
  // 関数呼び出し前
  // 例外を投げる前
  // 投げられた例外オブジェクトは 0 です
  // 捕まえた後
}