# 7.3 派生クラスへのポインター

クラスそれ自体のポインターであるthisポインターについて。

派生クラスは基底クラスのメンバーを継承しているので、あたかも基底クラスであるかのように使うことができました。
基底クラスのメンバーだけあれば問題ないような場合に、例えば基底クラスへのポインターや参照を引数として受け取るような関数がある場合に、派生クラスを渡すことができれば非常に便利です。
