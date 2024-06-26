# コンソールからの入力

## std::cin
標準ではコンソールからの入力のために**std::cin** というものが、std::cout と同じく<iosteram>で提供されています。
std::cin を使った入力では、逆方向の右シフト演算子(>>)を使います。
最初にユーザーに入力を促すメッセージのことを**プロンプト**と言います。

## 文字列の入力
何か数値を入力したい場合には、int型などの変数を用意してstd::cin から受け取ります。一方、入力して欲しいものが文字列であった場合には、その受け取り方が複数存在しまう。最も簡単な方法はstd::string型の変数を用意して、数値同様に受け取る方法です。もう一つはstd::getline() 関数を使う方法です。

この場合は空白を含んだ文字列の場合、無視され、次の空白のところまでしか取得できない。
std::string型へそのまま格納すると、最初の空白を除いた一単語分しか入力として受け取れません。

単語入力したい場合はこれで問題ないですが、入力された１行を全部受け取りたい場合には困ります。
入寮された文字列を１行丸々受け取るためにstd::getline() 関数を使います。

```
std::istream& getline(std::istream& input, std::string& str);
```
第一引数にはstd::cin を、第二引数には入力を受け取りたいstd::strin型の変数を渡します。
