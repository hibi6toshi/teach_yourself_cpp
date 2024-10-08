# 10.4 標準例外
## 10.4.1 std::exceptionとwhat()メンバー関数
標準ライブラリが投げる例外はすべて<exception>ヘッダーで定義されたstd::exception例外から派生しています。std::exceptionは次のようなwhat()メンバー関数を持っていて、例外に関数メッセージを取得できます。

```C++
// what()メンバー関数
virtual const char* what() const noexcept;
```

virtualとなっていることからも分かる通り、実際の例外に関数メッサージはstd::exceptionが持っているのではなく、それらから派生した各例外クラスが持っています。もし自分で独自の例外クラスを作成しようと思ったら、std::exceptionを規定クラスにしてwhat()メンバー関数をオーバーライドして適切なメッセージを返すようにするといいでしょう。

