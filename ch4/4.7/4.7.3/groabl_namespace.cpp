void feature();

namespace module {
  namespace submodule {
    void feature();
  }

  using namespace submodule; // submodule名前空間を省略可能にする
  
  void caller() {
    feature();  // module::submodule::feature() を呼び出す。
    ::feature(); // グローバル名前空間のfeature() を呼び出す。
  }
}