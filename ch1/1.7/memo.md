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
