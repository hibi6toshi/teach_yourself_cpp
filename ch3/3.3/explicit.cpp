class A {
  int m_v;
public:
  explicit A(int); // explicitキーワードを追加することで、
                   // 暗黙のコンストラクター呼び出しを禁止できる。
  int v() const;
};

A::A(int v) : m_v(v) {}

int A::v() const {
  return m_v;
}

int main() {
  // A x = 0; // コンパイルエラー
  A y(42); // OK 明示的なコンストラクター呼び出し
  y.v() == 42; // true
}