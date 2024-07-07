#include <iostream>

class Marker {
public:
  Marker();
  Marker(const Marker& other); // コピーコンストラクタの宣言
  ~Marker();
};

Marker::Marker() {
  std::cout << "コンストラクター: " << this << std::endl;  
}

// コピーコンストラクタの実装
Marker::Marker(const Marker& other) {
  std::cout << "コピーコンストラクター: " << this << " from " << &other << std::endl;
}

Marker::~Marker() {
  std::cout << "デストラクター: " << this << std::endl;
}

void copy(Marker m) {
  std::cout << "copy: " << &m << std::endl;
}

void reference(const Marker& m) {
  std::cout << "reference: " << &m << std::endl;
}

int main() {
  Marker m;
  std::cout << "値渡し前" << std::endl;
  copy(m);
  std::cout << "値渡し後" << std::endl;

  std::cout << "参照渡し前" << std::endl;
  reference(m);
  std::cout << "参照渡し後" << std::endl;
  
  // コンストラクター: 0x16dc1b070
  // 値渡し前
  // コピーコンストラクター: 0x16dc1b078 from 0x16dc1b070
  // copy: 0x16dc1b078
  // デストラクター: 0x16dc1b078
  // 値渡し後
  // 参照渡し前
  // reference: 0x16dc1b070
  // 参照渡し後
  // デストラクター: 0x16dc1b070
}
