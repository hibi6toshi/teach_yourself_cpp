# 12.3 std::list
std::vectorは連続するメモリ領域に隙間なく並んだ要素列でした。
それに対してstd::list(<list>ヘッダーで定義)は、各要素が「次の要素と前の要素を指す2つのポインター」を持っており、双方向のリンクで数珠繋ぎになっているコンテナです。
したっがて、std::listに対する要素の挿入・削除はリンクの張り替え（ポインターの付け替え）を行うのみで要素の移動を伴わないため、挿入・削除の位置によらず処理時間は一定（かつ高速）です。

## 12.3.1 std::listの基本動作
std::vectorで紹介した操作のうち、添字演算子を除く全ての操作が、std::listでもそのまま適用できます。ただし、std::listイテレーターは双方向イテレーターであることに注意してください。つまり、インクリメント/デクリメント演算子により1つずつ前後の要素へ移動できるものの、begin() + n のようにn個進んだり戻ったりすることはできません。

**双方向イテレーターの操作**
双方向イテレーターの操作について

ランダムアクセスイテレーターは、+演算子や-演算子に整数値を渡すことで指す要素を進めたり戻したりすることができました。
しかし双方向イテレーターにはそれらの演算子は用意されていないため、標準ライブラリの<iterator>ヘッダーに以下のように定義されているテンプレート関数を利用します。

```C++
// 双方向イテレーターを移動するためのテンプレート関数
template <typename Iterator, typename Distance>
void std::advance(Iterator* it, Distance n);

template <typename Iterator>
Iterator std::next(Iterator it, integer-type n =  1);

template <typename Iterator>
Iterator std::prev(Iterator it, integer-type n = 1);
```

このうち、std::advance()関数は第1引数に参照として受け取ったイテレーターを第2引数nだけ進めます(nが負の場合は戻します)。
他の2つ、std::next()関数とstd::prev()関数は、第1引数に受けたイテレーターをコピーして、第2引数だけ
- std::next()関数では進めて
- std::prev()関数では戻して
戻り値として返します。std::advance()関数と異なり、第1引数として渡したイテレーター自体は変更されません。

## 12.3.2 std::listの特徴
std::listでは格要素が（順方向と逆方向）双方向リンクで1本の鎖を構成し、要素の挿入・削除や順序の入れ替えをリンク（ポインター）の張り替えで実現しているため、std::vectorではできなかった様々な操作がメンバー関数として定義されています。

**要素の挿入・削除**
まず、末尾要素の挿入・削除うを行うpush_back()メンバー関数、emplace_back()メンバー関数、pop_buck()メンバー関数に加え、push_front()メンバー関数、emplace_front()メンバー関数、pop_front()メンバー関数で先頭要素の挿入・削除が行えます。
```C++
void push_front(const T& value);

template <typename... T>
void emplace_front(T&&... args);

void pop_front();
```

std:listに対する要素の追加・削除の際には、std::vectorとは異なりイテレーターが無効となりません。

**要素の移動**
2つのstd::list間で要素の移動を行うには、splice()メンバー関数を使います。
std::vectorでは一方に挿入し、他方から削除することになるため、対象要素の生成・破棄・コピーが伴いますが、std::listではsplice()メンバー関数を使えば、リンクの張り替えだけで要素の移動が行えます。

```C++
void splice(const_iterator pos, std::list<T>& other);

void splice(const_iterator pos, std::list<T>& other, const_iterator it);

void splice(const_iterator pos, std:list<T>& other, const_iterator first, const_iterator last);
```

1つ目のオーバーロードはotherで指定されたstd::listの全ての要素をposで指定した場所に移動します。
2つ目はitで指定された要素のみを、3つ目ではfirstとlastで指定された範囲の要素全部を移動します。

**ソート**
std::vectorでは、標準アルゴリズムを使ってソートを行います。
しかし、標準アルゴリズムはランダムアクセスイテレーターを要求していてstd::listでは使うことができないので、std::list自体がソートのためのsort()メンバー関数と、ソートされた2つのstd::listを併合するmerge()メンバー関数を持っています。
```C++
void sort();

template <typename Compare>
void sort(Compare comp);

void merge(list& other);

template <typename Compare>
void merge(std::list<T>& other, Compare comp);
```

sort()メンバー関数もmerge()メンバー関数も、通常は小なりの比較演算子（<）を使って照準に並べますが、それ以外の並べ方をしたい場合には、要素の比較をするための関数を第2引数に渡すことで、好きな順番で並べることができます。
