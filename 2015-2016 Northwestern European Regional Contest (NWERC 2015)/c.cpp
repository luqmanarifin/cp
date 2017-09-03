#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const double eps = 1e-7;

struct Point {
  Point() {}
  Point(int x, int y) : x(x), y(y) {}
  bool operator==(Point p) {
    return x == p.x && y == p.y;
  }
  int x, y;
};

bool intersect(Point p1, Point p2, Point p3, Point p4) {
  // Store the values for fast access and easy
  // equations-to-code conversion
  long long x1 = p1.x, x2 = p2.x, x3 = p3.x, x4 = p4.x;
  long long y1 = p1.y, y2 = p2.y, y3 = p3.y, y4 = p4.y;
  if (p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4) return 1;
  
  //printf("(%d, %d) to (%d, %d) with (%d, %d) to (%d, %d)\n", x1, y1, x2, y2, x3, y3, x4, y4);
  
  long long d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
  // If d is zero, there is no intersection
  //cout << d << endl;
  if (d == 0) return 0;
   
  // Get the x and y
  long long pre = (x1*y2 - y1*x2), post = (x3*y4 - y3*x4);
  double x = double( pre * (x3 - x4) - (x1 - x2) * post ) / d;
  double y = double( pre * (y3 - y4) - (y1 - y2) * post ) / d;
   
  // Check if the x and y coordinates are within both lines
  if ( x < min(x1, x2) - eps || x > max(x1, x2) + eps || x < min(x3, x4) - eps || x > max(x3, x4) + eps ) return 0;
  if ( y < min(y1, y2) - eps || y > max(y1, y2) + eps || y < min(y3, y4) - eps || y > max(y3, y4) + eps ) return 0;
   
  // Return the point of intersection
  return 1;
}

vector<int> edge[N];
Point well[N], to[N];
int from[N];
int c[N];

bool dfs(int now, int col) {
  if (c[now] != -1) {
    if (c[now] != col) return 0;
    return 1;
  }
  c[now] = col;
  for (auto it : edge[now]) {
    if (dfs(it, col ^ 1) == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &well[i].x, &well[i].y);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d %d %d", from + i, &to[i].x, &to[i].y);
  }
  for (int i = 1; i <= m; i++) {
    for (int j = i + 1; j <= m; j++) {
      if (from[i] == from[j]) continue;
      //printf("check %d %d\n", i, j);
      if (intersect(well[from[i]], to[i], well[from[j]], to[j])) {
        //printf("%d %d\n", i, j);
        edge[i].push_back(j);
        edge[j].push_back(i);
      }
    }
  }
  memset(c, -1, sizeof(c));
  for (int i = 1; i <= m; i++) {
    if (c[i] == -1) {
      if (dfs(i, 0) == 0) {
        puts("impossible");
        return 0;
      }
    }
  }
  puts("possible");
  return 0;
}