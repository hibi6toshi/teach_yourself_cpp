#include <new> // std::bad_alloc例外に必要
#include <iostream>

int main() {
  try {
    int len = 5;
    int* array = new int[len]{0, 1, 2, 3, 4, 5}; // 6要素で初期化しようとする

    // ... 何かしらの処理

    delete [] array;
  } catch (std::bad_array_new_length& e) { // 実際に確保する動的配列の長さより初期化リストの方が長かった場合の例外ハンドラー
    std::cout << "動的配列の長さが足りません" << std::endl;
  } catch (std::bad_alloc& e) { // メモリ割り当てが失敗した場合の例外ハンドラー
    std::cout << "メモリ割り当てに失敗しました" << std::endl;
  }
}