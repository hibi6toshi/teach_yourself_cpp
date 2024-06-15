#include <iostream>

using integer = int; // int に integer という別名をつける

integer main() { // interger はintの別名なので、intと同じように使える
    int value = 42; // 別名があっても、元の型名を使うこともできる
    
    using number = integer; // さらに別名をつけることもできる

    number num = 0;

    value = num; // あくまで別名なので実際の型は同じ

    return 0;
}