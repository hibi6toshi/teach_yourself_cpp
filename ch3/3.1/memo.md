# クラス
オブジェクト指向言語にもオブジェクトの作り方によって様々な種類がありますが、C++では**クラスベースプログラミング**というスタイルで記述します。これはクラスというオブジェクトの設計図をあらかじめ用意しておき、必要になったら実際のオブジェクト（インスタンス）を作成（インスタンス化）して使用する　というスタイルです。

## constメンバー関数とmutable
### メンバー変数を変更する/しない関数
クラスは秘匿されたメンバー変数や、他のメンバー関数を使って様々な機能（メンバー関数など）をクラスの外部に提供できます。
しかし、メンバー関数がメンバー変数を変更するかどうかは一眼見ただけではわからないので、コンパイラーは基本的にメンバー関数を「メンバー変数を変更するかもしれないもの」として扱います。そのため、constな（変更できない）インスタンスに対する、メンバー変数を変更するかもしれないメンバー関数の呼び出しをエラーとして処理します。

メンバー変数を変更するようなsetterなどをconstなインスタンスでも呼べてしまうと、インスタンスがconstとなっているため、呼び出しできないことは理解できる。
しかし、本来はメンバー変数を変更しないメンバー関数は呼べても問題なさそうです。そのようなメンバー関数を区別するために、C++には**constメンバー変数**という機能があります。

constメンバー関数は、インスタンスがconstとなっていても呼び出すことができるメンバー関数のことです。その代わりconstメンバー関数の本体でメンバー変数を変更しようとするとその場所でエラーになります。（constでないインスタンスからも、constメンバー関数を呼び出すことはできます。）

メンバー関数をconstメンバー関数にするには、宣言と定義のどちらにも指定が必要です。ただし、呼び出す時には通常のメンバー関数と同様の構文で呼び出せます。
```C++
class class-name {
  public:
   // constメンバー関数の宣言
   return-type member-function-name(parameters) const;
};

// constメンバー関数の定義
return-type class-name::member-function-name(parameters) const {
  function-body...
}
```

### const/非constメンバー関数間のオーバーロード
関数オーバーロードは、引数の型・数が異なる同盟の関数を複数定義できる機能でした。メンバー関数でもそれは同様ですが、さらにconstメンバー関数かそうでないかでもオーバーロードすることが可能です。この場合には引数の型・数が全く同じでも問題ありません。

全く同じ引数を受け取るメンバー関数があった場合、どちらのメンバー関数が呼ばれるかはインスタンスがconstかどうかに依存します。インスタンスがconstでない場合には非constメンバー関数が優先的に、constの場合にはconstメンバー関数がそれぞれ呼ばれます。

### constメンバー関数でも書き込みを行いたい場合
ごく稀にconstなメンバー関数からも書き込みをしたいメンバー変数というものがありえます。例えばクラスが返すデータが非常に大きく、毎回1からデータを作っているとプログラムがとても遅くなってしまう場合を考えてください。
もしクラスに変更がない場合に同じデータを返すことができるのであれば、以前に作成したデータを**キャッシュ**しておいて、それを返すようにすると最初の1回以外は高速に処理できます。

データを取得するためのメンバー関数は通常constメンバー関数となっているので、生成したデータをキャッシュに保存しようとしてもそのままでは代入ができません。こういった場合、メンバー変数にmutableという指定をすることで、constメンバー関数からでも書き換える操作ができるようになります。
