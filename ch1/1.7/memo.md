# 繰り返し

## while 文
条件式(condition)がtrueとなる限り {} で囲まれた処理をずっと繰り返す構文です。
```
while (condition) {
  statements...;
}
```

## break文とcontinue文

## for文

```
for (initializer-expression; condition; post-iteration-expression){
 statements...;
}
```

for文をwhile文を使って表現するとこうなる。
```
initializer-expression;
while (condition) {
  statements...;

  post-iteration-expression;
}
```
for文はいかなる場合でも post-iteration-expressionが実行される。

## 範囲for文
```
for (type variable : range) {
  statements...;
}
```
 
範囲for文を通常のfor文で書き直すと、以下のようになる。
```
for(int i = 0; i < length-of-range; i++) {
  type varialbe = range[i];
  statements...;
}
```
コンパイラは配列の長さを知っているので、その長さを自動的に使って走査します。
ただし、今扱っているのが何番目の要素かを知る方法はありません。

## do文
必ず一度は本体を実行してからループの継続を判断したい場合。
```
do {
  statements...;
} while (condition);
```
while の後ろには;(セミコロン)が必要