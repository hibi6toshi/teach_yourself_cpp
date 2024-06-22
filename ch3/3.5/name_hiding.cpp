class Base {
public:
  void public_member();
};

class Derived : public Base {
public:
  void public_member(int i); // 派生クラスでオーバーロードを追加した
};

int main() {
  Derived d;
  d.public_member(0); // OK 派生クラスのメンバー関数が呼ばれる
  d.public_member(); // エラー 派生クラスでオーバーロードされたメンバー関数が隠蔽される
                     // 基底クラスから継承したメンバー関数を呼び出したい
}