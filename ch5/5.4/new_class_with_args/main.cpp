#include <iostream>

class Triangle{
  float height;
  float width;

public:
  explicit Triangle(float height, float width);
  float area() const;
};

Triangle::Triangle(float height, float width) : height(height), width(width) {}

float Triangle::area() const {
  return height * width / 2;
}

int main() {
  Triangle* tri = new Triangle{10.0f, 5.0f};
  std::cout << "Area: " << tri->area() << std::endl;

  delete tri;
}
