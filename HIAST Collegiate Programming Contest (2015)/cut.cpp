#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-7;

struct point {
  point(double x, double y) : x(x), y(y) {}
  double x, y;
};

double cross(point p, point q, point r) {
  return (p.x - q.x) * (r.y - q.y) - (p.y - q.y) * (r.x - q.x);
}

// line segment p-q intersect with line A-B
point lineIntersectSeg(point p, point q, point A, point B) {
  double a = B.y - A.y;
  double b = A.x - B.x;
  double c = B.x * A.y - A.x * B.y;
  double u = fabs(a * p.x + b * p.y + c);
  double v = fabs(a * q.x + b * q.y + c);
  return point((p.x*v + q.x*u)/(u+v), (p.y*v + q.y*u)/(u+v));
}
// cuts polygon Q along the line formed by point a-> point b
// (note: the last point must be the same as the first point)
vector<point> cutPolygon(point a, point b, vector<point> Q) {
  vector<point> P;
  for(int i = 0; i<(int)Q.size(); i++) {
      double left1 = cross(a, b, Q[i]), left2 = 0.0;
      if(i != (int)Q.size()-1) left2 = cross(a, b, Q[i+1]);
      if(left1 > -EPS) P.push_back(Q[i]);
      if(left1 * left2 < -EPS)
          P.push_back(lineIntersectSeg(Q[i], Q[i+1], a, b));
  }

  if(P.empty()) return P;
  if(fabs(P.back().x - P.front().x) > EPS || fabs(P.back().y - P.front().y) > EPS)
    P.push_back(P.front());
  return P;
}

double area(const vector< point > & P) {
  double result = 0.0;
  for(int i = 0; i< (int)P.size()-1; i++) {
    result += (P[i].x * P[i+1].y - P[i].y*P[i+1].x);
  }
  return fabs(result)/2.0;
}

void print(vector<point> p) {
  for(auto it : p) {
    printf("%.2f %.2f\n", it.x, it.y);
  }
  printf("\n");
}

int main() {
  vector<point> p;
  p.push_back(point(0, 0));
  p.push_back(point(1, 0));
  p.push_back(point(1, 1));
  p.push_back(point(0, 1));
  p.push_back(point(0, 0));
  point b = point(0.25, 0.2);
  point a = point(0.2, 0.3);
  vector<point> ccw = cutPolygon(a, b, p);
  print(ccw);
  
  vector<point> q;
  q.push_back(point(0, 0));
  q.push_back(point(0, 1));
  q.push_back(point(1, 1));
  q.push_back(point(1, 0));
  q.push_back(point(0, 0));
  vector<point> cw = cutPolygon(a, b, q);
  print(cw);
  return 0;
}