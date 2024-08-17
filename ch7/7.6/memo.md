# 7.6 仮想基底クラス

多重継承では、継承関係によって基底クラスが曖昧になってしまう場合がありました。
基底クラスを指定して呼び出す他に、C++では**仮想基底クラス**という仕組みも提供されています。

## 7.6.1 ひし形継承
仮想基底クラスを使用しない場合では、重複する基底クラスは複数存在していました。
仮想基底クラスを使用すると、DerivedAかDerivedBなのかに関係なく、Baseはただ一つしか存在しないようにクラスが作成されます。
この場合、基底クラスはただ1つしか存在しないので、前節にエラーになったようなメンバー関数呼び出しも曖昧になることなく呼び出すことができます。

仮想基底クラスを使った継承は図示したときにひし形に見えることから、**ひし型継承**や**ダイヤモンド継承**と呼ばれます。
派生クラスで仮想基底クラスを指定するには、継承する際に仮想基底クラスとしたい基底クラスをvirtualというキーワードを使って指定します。