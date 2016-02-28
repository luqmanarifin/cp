#include <bits/stdc++.h>

using namespace std;

class Point{
    public:
        double x, y;
        Point(double px, double py) {
            x = px;
            y = py;
        }
        Point sub(Point p2) {
            return Point(x - p2.x, y - p2.y);
        }
        Point add(Point p2) {
            return Point(x + p2.x, y + p2.y);
        }
        double distance(Point p2) {
            return sqrt((x - p2.x)*(x - p2.x) + (y - p2.y)*(y - p2.y));
        }
        Point normal() {
            double length = sqrt(x*x + y*y);
            return Point(x/length, y/length);
        }
        Point scale(double s) {
            return Point(x*s, y*s);
        }
};

class Circle {
    public:
        double x, y, r, left;
        Circle(double cx, double cy, double cr) {
            x = cx;
            y = cy;
            r = cr;
            left = x - r;
        }
        pair<Point, Point> intersections(Circle c) {
            Point P0(x, y);
            Point P1(c.x, c.y);
            double d, a, h;
            d = P0.distance(P1);
            a = (r*r - c.r*c.r + d*d)/(2*d);
            h = sqrt(r*r - a*a);
            Point P2 = P1.sub(P0).scale(a/d).add(P0);
            double x3, y3, x4, y4;
            x3 = P2.x + h*(P1.y - P0.y)/d;
            y3 = P2.y - h*(P1.x - P0.x)/d;
            x4 = P2.x - h*(P1.y - P0.y)/d;
            y4 = P2.y + h*(P1.x - P0.x)/d;

            return pair<Point, Point>(Point(x3, y3), Point(x4, y4));
        }

};

#define PI acos(-1.)

int main() {
  double x1, y1, r1, x2, y2, r2;
  scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);
  double d = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
  if(d >= r1 + r2) {
    puts("0");
    return 0;
  }
  if(d <= abs(r1 - r2)) {
    printf("%.15f\n", PI * min(r1, r2) * min(r1, r2));
    return 0;
  }
  long double r = r1;
  long double R = r2;
  if(R < r){
      // swap
      r = radius2;
      R = radius1;
  }
  long double part1 = r*r*Math.acos((d*d + r*r - R*R)/(2*d*r));
  long double part2 = R*R*Math.acos((d*d + R*R - r*r)/(2*d*R));
  long double part3 = 0.5*Math.sqrt((-d+r+R)*(d+r-R)*(d-r+R)*(d+r+R));

  long double intersectionArea = part1 + part2 - part3;
  return 0;
}