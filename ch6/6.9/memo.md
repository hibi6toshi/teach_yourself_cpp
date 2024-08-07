## 6.9 フレンドな演算子オーバーロード
これまで演算子のオーバーロードはクラスのメンバー関数として説明してきました。しかし一部の演算子（特に二項演算子）については、メンバー関数よりも通常の関数としないとうまく動かない場合があります。
二項演算子をメンバー関数にしてしまうと、インスタンスが演算子の左辺にあった場合には正しくオーバーロードされるのですが、右側にある場合にはオーバーロードは呼ばれません。自分で作成した整数クラスと組み込みの整数型とで加算できるようにしたい場合、Integer{1} + 2 も左右を入れ替えた1 + Integer{2} も同じ計算をして欲しいはずですが、演算子オーバーロードがメンバー関数となっていると前者の場合にしか対応させることができません。
このようなとき、演算子オーバーロードをメンバー関数ではなく通常の関数として定義することで、どちらの場合にも対応することができます。
多くの場合、演算子はクラスのプライベートメンバー変数などを使っているので、単なる通常の関数ではなくフレンド関数とすることで、カプセル化によるアクセス制御を維持したまま演算子をさまざまな状況に対応させることができます。
