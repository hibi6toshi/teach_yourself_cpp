# 12.6 アルゴリズム
標準ライブラリのアルゴリズムはイテレーターを使って処理するので、アルゴリズムが求めているイテレーターの種類を満たせば、具体的なコンテナが何であろうともアルゴリズムを使うことができます。標準ライブラリのアルゴリズムはほとんどが<algorithm>ヘッダーで提供されていますが、一部は<numeric>ヘッダーで提供されてます。

## 12.6.1 高階関数と関数オブジェクト
アルゴリズムはそのほとんどが高階関数となっており、アルゴリズムの動作をプログラマーが変更できます。高階関数は何も関数ポインターを受け取る関数だけというわけではなく、関数のように呼び出せるものを受け取る関数は全て高階関数です。関数のように呼び出せるものとしては関数オブジェクトやラムダ式がありました。

関数ポインターと違い、関数オブジェクトやラムダ式はそれぞれが異なった型（クラス）を持つため、それらを受け取るようにするには関数テンプレートにするのが一般的な手法です。

## 12.6.2 変更を加えないアルゴリズム
変更を加えないアルゴリズムはコンテナの中から何かを探し出したり、数えたり、コンテナが何かの条件を満たすかをチェックしたりするものです。
代表的なアルゴリズムはfindアルゴリズムとcountアルゴリズムです。
```C++
template <typename InputIterator, typename T>
InputIterator find(InpoutIterator first, InputIterator last, const T& value);

template <typename InputIterator, typename Predicate>
InputIterator find_if(InputIterator first, InputIterator last, Predicate predicate);
```
std::find()関数は[first, last)の範囲をfirstからlastに向かって検索し、最初にvalueと同じ要素を持つイテレーターを返します。
std::find_if()関数は[first, last)の範囲をfirstからlastに向かって検索し、最初にpredicateがtrueを返すイテレーターを返します。
どちらの関数も目的の要素が見つからなければlastを返します。

findアルゴリズムはイテレーターを返しましたが、countアルゴリズムは一致した数を返すアルゴリズムです
stdt::count()関数は与えられた要素を、std::count_if()関数は関数オブジェクトがtrueを返すものを数えて返します。
数を返すアルゴリズムなので見つからなければ0が返されます。
```C++
template <typename InputIterator, typename T>
integer-type count(InputIterator first, InputIterator last, const T7 value);

template <typename InputIterator, typename P>
integer-type count_if(InputIterator first, InputIterator last, P predicate);
```
