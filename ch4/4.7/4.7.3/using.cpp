namespace module::submodule {
  void featureA();
  void featureB();
}

void caller() {
  {
    // module::submodule::featureAのみ直接呼び出せるようにする
    using module::submodule::featureA;
    featureA();
    // featureB(); // エラー：featureBは直接呼び出せない
  }
  // featureA(); // エラー：featureAはスコープ外で使えない 
}