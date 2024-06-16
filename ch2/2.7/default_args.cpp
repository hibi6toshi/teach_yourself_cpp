// bとcの実引数が省略された場合、デフォルト値(0)が使われる
int sum(int a, int b=  0, int c = 0){
  return a + b + c;
}

int main() {
  sum(1, 2, 3); // 6
  sum(4, 6); // 10 (b = 6, c = 0)
  sum(5); // 5 (b = 0, c = 0)
}