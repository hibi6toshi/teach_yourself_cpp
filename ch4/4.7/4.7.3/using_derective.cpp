namespace module::submodule {
  void feature();
}

void caller() {
  {
    using namespace module; // このスコープ内で module 名前空間の名前を省略して使える
    submodule::feature(); // module::submodule::feature()
  }

  // submodule::feature(); // エラー：module 名前空間が見つからない
}