// Author: Luka Kalinovcic
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

double const eps = 1e-9;
bool lt(double a, double b) { return a + eps < b; }
bool lte(double a, double b) { return !lt(b, a); }

struct Point {
  double x, y;
};

double GetArea(vector<Point> const& poly) {
  double area = 0.0;
  for (int i = 0; i < poly.size(); ++i) {
    int j = i + 1 == poly.size() ? 0 : i + 1;
    area += (poly[j].x - poly[i].x) * (poly[i].y + poly[j].y) / 2;
  }
  return fabs(area);
}

pair<vector<Point>, vector<Point>> HorizontalSplit(vector<Point> const& poly, double x) {
  vector<Point> left;
  vector<Point> right;
  for (int i = 0; i < poly.size(); ++i) {
    int j = i + 1 == poly.size() ? 0 : i + 1;
    if (lte(poly[i].x, x)) left.push_back(poly[i]);
    if (lte(x, poly[i].x)) right.push_back(poly[i]);

    if (lt(poly[i].x, x) && lt(x, poly[j].x) ||
        lt(poly[j].x, x) && lt(x, poly[i].x)) {
      double dx = poly[j].x - poly[i].x;
      double dy = poly[j].y - poly[i].y;
      Point t;
      t.x = x;
      t.y = poly[i].y + dy * (x - poly[i].x) / dx;
      left.push_back(t);
      right.push_back(t);
    }
  }
  return make_pair(left, right);
}

pair<vector<Point>, vector<Point>> VerticalSplit(vector<Point> const& poly, double y) {
  vector<Point> bottom;
  vector<Point> top;
  for (int i = 0; i < poly.size(); ++i) {
    int j = i + 1 == poly.size() ? 0 : i + 1;
    if (lte(poly[i].y, y)) bottom.push_back(poly[i]);
    if (lte(y, poly[i].y)) top.push_back(poly[i]);

    if (lt(poly[i].y, y) && lt(y, poly[j].y) ||
        lt(poly[j].y, y) && lt(y, poly[i].y)) {
      double dx = poly[j].x - poly[i].x;
      double dy = poly[j].y - poly[i].y;
      Point t;
      t.x = poly[i].x + dx * (y - poly[i].y) / dy;
      t.y = y;
      bottom.push_back(t);
      top.push_back(t);
    }
  }
  return make_pair(bottom, top);
}

int main() {
  vector<Point> box;
  for (int i = 0; i < 4; ++i) {
    Point p;
    scanf("%lf%lf", &p.x, &p.y);
    box.push_back(p);
  }
  vector<Point> left = HorizontalSplit(box, -0.5).first;
  vector<Point> right = HorizontalSplit(box, 0.5).second;
  vector<Point> bottom = VerticalSplit(box, -0.5).first;
  vector<Point> top = VerticalSplit(box, 0.5).second;

  printf("%.10lf\n",
         (5 * (4 * 5 * 5) + 6 * (5 * GetArea(top)) + 4 * (5 * GetArea(left)) +
          1 * (5 * GetArea(bottom)) + 3 * (5 * GetArea(right))) /
             (5 * 5 * 5 - 1));
  return 0;
}
