class C {
  int default_member; // デフォルトはprivate
  
  public: 
    int public_menber; // publicなメンバー

  private:
    int private_member; // privateなメンバー  
};

int main() {
  C c;
  c.public_menber = 0; // OK
  c.private_member = 0; // コンパイルエラー
  c.default_member = 0; // コンパイルエラー
}