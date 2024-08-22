class Base {};

// もうこれ以上派生出来なくする
class FinalClass final : public Base {};

// エラー final指定されたクラスを継承することはできない
class MoreDerived : public FinalClass {};
// main.cpp:7:7: error: cannot derive from 'final' base 'FinalClass' in derived type 'MoreDerived'
//     7 | class MoreDerived : public FinalClass {};