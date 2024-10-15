# 12.2 std::vector
std::vectorはstd::stringと並んで最も使用頻度の高い代表的なコンテナです。
std::vectorは各要素が隙間なく連続していることが保証されています。
そのためstd::vectorの要素へのアクセスは配列と同じ速度でできるようになっています。

std::vectorには、コンテナに対する基本的な操作
- インスタンスの生成・破棄
- イテレーターによる要素のアクセス
- 代入・削除
を持っています。

## 12.2.1 インスタンスの生成と破棄
**空のコンテナの生成**
int型を要素とし、要素数0すなわち内部に要素を持たない空のstd::vectorを生成するには以下のように記述します。
```C++
std::vector<int> iv;
``

**要素数nのコンテナの生成**
5つのstd::string("apple")を要素とするstd::vectorを生成するには、以下のように記述します。
```C++
std::vector<std::string> sv{5, "apple"};
```

要素がデフォルトコンストラクターもしくは規定値を持っている場合は第2引数を省略でき、以下のように記述することができます。この場合、svには5つの空文字列が格納されています。
```C++
std;:vector<std::string> sv{5};
```

**コンテナのイテレーター**
std::vectorに限らず、コンテナは基本的に先頭と末尾の次を指すイテレーターを、それぞれbegin()メンバー関数とend()メンバー関数で取得できるようになっています。そしてbegin()メンバー関数とendメンバー関数でイテレーターを取得できるコンテナは範囲for文で走査させることができるようになっています。
なお、std::vetorはランダムアクセスができるコンテナであり、そのイテレーターはランダムアクセスイテレーターです。

**イテレーターに呼ぶインスタンス生成**
コンストラクターにイテレーターを2つ与えることで、そのイテレーターが指す範囲の要素群（例）によりインスタンスが生成されます。
そこで、"apple"というstd::string型の変数sの先頭(s.begin())と末尾の次(s.end())を引数に取るコンストラクターでstdd::vector<char>を生成する例

```C++
  std::string s = "apple";

  // sの先頭から末尾をもとに、std::vectorを生成する
  std::vector<char> cv{s.begin(), s.end()};
```
この例では、s.begin()が'a'を、s.end()が'e'の直後を指すので、cvには'a', 'p', 'p', 'l', 'e' が格納されます。
ポインターもまたイテレーターとして機能するため、以下のようにインスタンスを生成することも可能です。
```C++
const char fruit[] = "apple";
std::vector<char> cv{fruit, fruit + 5}; // fruitの先頭と6文字目（末尾）
```

**std::initializer_listによるインスタンス生成**
std::initializer_list<int>の各要素1~5がivに格納されます。
見かけと、配列の初期化と同じ記述になっています。

```C++
  // std::intializer_listによる生成
  std::vector<int> iv = {1, 2, 3, 4, 5};
```

**初期化文からの型推論**
std::vectorはクラステンプレートの型推論をサポートしています。

```C++
std::vector iv = { 0, 1, 2, 3, 4}; // std::vector<int>に推論される
```

**コピー**
std::vectorのコピーを作るには、以下のように記述します。
iv1にiv0の各要素がコピーされます。

```C++
  std::vector iv0 = { 1, 2, 3, 4, 5}; // コピー元
  std::vector iv1 = iv0; // コピー
```

**リサイズ**
配列と比べた際の動的配列の利点は、後から長さを変えられることにあります。resize()メンバー関数を使うことで、好きなタイミングで好きな長さに変更できます。

```C++
void resize(size_type n);

void resize(size_type n, const T& value);
```

このとき、短くする場合にはオーバーしている後ろの要素が破棄され、長くする場合には新規に増える部分はデフォルト値もしくは第2引数に渡した値を使って初期化されます。

**インスタンスの破棄**
std::vector<T>が破棄されるとき、格納されていた要素も全て破棄されます。
ただし、std::vector<T>の要素Tがポインターである場合は、ポインターの破棄の際にdelete(delete [])が自動的に行われないため注意しましょう。

以下のコードではメモリリークになります。
```C++
{
  char* pa = new char[5];
  char* pb = new char[10];

  std::vector pv = { pa, pb };

  ...

  // ここでstd::vector内のポインターは破棄されるが、
  // delete[]されないのでメモリリークとなる
}
```

## 12.2.2. 代入
std::vectorへの代入は、代入演算子を用いる方法とassign()メンバー関数を用いる方法とがあります。

**代入演算子**
代入演算子によって代入できるのは、(テンプレート引数も含めて)同じ型のコンテナ、もしくはstd::initializer_list<T>です。
```C++
  std::vector v0 = { 0, 2, 4, 6, 8};

  v0 = { 2, 3, 5 }; // std::initializer_list<int>からの代入
```

**assign()メンバー関数**
assign()メンバー関数を使うと
- イテレーターの組
- 任意個数の複数要素
- std::initializer_list<T>

による要素の差し替えが可能です。

std::vector<T>で、assign()メンバー関数は以下のように定義されています。
これらはコンストラクターで渡せるものと同じものを受け取るようになっています。
```C++
// assign()メンバー関数
temlate<typename Iterator>
void assign(Iterator first, Iterator last);

void assign(size_type n, const T& u);

void assign(std::itnializer_list<T> il);
```

## 12.2.3 要素へのアクセス
**添字演算子によるアクセス**
std::vectorは通常の配列と同じ操作で扱えるクラスであり、添字演算子を持っています。
```C++
std::vector iv = { 0, 1, 2, 3, 4 };

iv[2] = 10; // OK
```

**イテレーターによるアクセス**
コンテナ内の各要素にはイテレーターをつかてアクセスでき、その際、要素の値はポインターと同様に関節参照演算子を使って取得できます。
例えば、begin()メンバー関数とend()メンバー関数は、それぞれ「先頭要素」と「末尾要素の次」を指すため、範囲[begin(), end())がコンテナ内の全要素となります。

```C++
// begin()/end()メンバー関数
iterator begin()

iterator end();
```

**const_iterator**
コンテナがconstで会ったとき、begin()/end()メンバー関数は要素の書き換えができないstd::vector<T>::const_iteratorを返します。
```C++
const std::vector v = { 0, 1, 2, 3 ,4 };

*v.begin() = -1; // コンパイルエラー
int first_value = *v.begin(); // OK
```
また、cbegin()/cendメンバー関数は、コンテナがconstであるか否かに関わらず、std::vector<T>>::coust_iteratorを返します。

**逆順のイテレーター**
begin()/end()、cbegin()/cend()メンバー関数が返すイテレーターは、インクリメント(++)したときにコンテナ内を先頭から末尾に向かって進みます。
一方、rbegin()/rend、crbegin()/crend()メンバー関数は末尾から先頭に向かって進みます。
```C++
reverse_iterator rbegin();

reverse_iterator rend();
```
