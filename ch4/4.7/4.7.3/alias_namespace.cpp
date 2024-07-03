namespace module::submodule {
  void feature();
}

void caller() {
  namespace sub = module::submodule; // subという別名を与える

  // modlue::submoduleのfeature() を呼び出す。
  sub::feature();
}