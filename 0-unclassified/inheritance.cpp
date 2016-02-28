#include <iostream>
#include <iomanip>
using namespace std;

class Polygon {
protected:
    double width;
    double height;
public:
    Polygon(double _width, double _height) {
        width  = _width;
        height = _height;
    }
    virtual double area() = 0;
};

class Rectangle : public Polygon {
public:
  Rectangle (double w, double h) : Polygon(w, h) {

  }
  double area() {
    return width * height;
  }
};

class Triangle : public Polygon {
public:
  Triangle (double w, double h) : Polygon(w, h) {

  }
  double area() {
    return width * height / 2;
  }
};

int main()
{
    double width, height;
    cin >> width >> height;

    Polygon *rectangle = new Rectangle(width, height);
    Polygon *triangle  = new Triangle(width, height);

    cout << setprecision(1) << fixed << rectangle->area() << "\n"  <<triangle->area() << endl;

    return 0;
}