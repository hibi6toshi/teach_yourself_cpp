# switch文
条件分岐にはif文の他に**switch文**が存在する。switch文の条件には結果が整数になる簡単な条件しかかけない。
デフォルトの処理が必要ないのであれ、defaultラベルは省略することができる。
デフォルトの位置は関係ない。（defaultの後に一致するケースを書いても、一致するケースの処理が実施される。）
```
switch (condition) {
  case selection1:
    selection1-statement...
    break;

  case selection2:
    selection2-statement...
    break;

  ...
  case selectionN;
    selectionN-statement...
    break;
  
  default:
    default-statement....
    break;
}
```

# goto文
goto文のあるところまで処理が到達すると、同じ関数内の対応するラベルのところに強制的に処理を移す制御構文。
ラベルはgoto文より前にあっても、後ろにあっても問題ない。（ただし同じ関数内にある必要がある。）
```
label:

goto label;
```



