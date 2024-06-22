#include <iostream>

// 図形の形状（面積、周囲長）を扱うクラスを作成する。
// 計算方法は各図形ごとに異なるので、それぞれの図形クラスでオーバーライドして実装する。

// 面積や周囲長は各図形ごとに異なるので、仮想関数として宣言する。
class Shape {
public:
  virtual float area() const = 0; // 面積を求める純粋仮想関数
  virtual float perimeter() const = 0; // 周囲長を求める純粋仮想関数
};

// 純粋仮想関数は関数本体を持たないので、メンバー関数の定義はない
// 長方形を扱うクラス
class Rectangle : public Shape {
  float height; // 高さ
  float width; // 幅

public:
  explicit Rectangle(float height, float width);
  float area() const override;
  float perimeter() const override;
};

Rectangle::Rectangle(float height, float width) 
  : height(height), width(width) {} 

float Rectangle::area() const {
  return height * width;
}

float Rectangle::perimeter() const {
  return 2 * (height + width);
}

class Circle : public Shape {
  float r; // 半径

public:
  explicit Circle(float r);
  float area() const override;
  float perimeter() const override; 
};

Circle::Circle(float r) : r(r) {}

float Circle::area() const {
  return r * r * 3.14f;
}

float Circle::perimeter() const {
  return 2 * r * 3.14f;
}

int main() {
  Rectangle rect(10, 2);
  std::cout << "rect" << std::endl;
  std::cout << " Area: " << rect.area() << std::endl; // 20
  std::cout << " Perimeter: " << rect.perimeter() << std::endl; // 24

  Circle circle(4);
  std::cout << "circle" << std::endl;
  std::cout << " Area: " << circle.area() << std::endl; // 50.24
  std::cout << " Perimeter: " << circle.perimeter() << std::endl; // 25.12
}