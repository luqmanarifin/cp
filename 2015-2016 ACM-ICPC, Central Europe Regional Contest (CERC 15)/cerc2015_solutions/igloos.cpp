// Author: Luka Kalinovcic
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

#define MAX_COORDS 1000

double r[MAX_COORDS][MAX_COORDS];

double a, b, c;
double k, l;

void InitPravac(int x1, int y1, int x2, int y2) {
  a = (y2 - y1);
  b = (x1 - x2);
  double norm = sqrt(a * a + b * b);
  a /= norm;
  b /= norm;
  c = -(a * x1 + b * y1);

  k = (double) (y2 - y1) / (x2 - x1);
  l = y1 - k * x1;
}

double GetY(int x) {
  return k * x + l;
}

double Dist(int x, int y) {
  return fabs(a * x + b * y + c);
}

int Count(int x, int y1, int y2) {
  int ret = 0;
  for (int y = y1; y <= y2; ++y) {
    ret += r[x][y] > 0.0 && Dist(x, y) <= r[x][y];
  }
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    double radius;
    scanf("%d%d%lf", &x, &y, &radius); --x; --y;
    r[x][y] = radius;
  }

  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2); --x1; --y1; --x2; --y2;
    if (x1 > x2 || x1 == x2 && y1 > y2) {
      swap(x1, x2);
      swap(y1, y2);
    }
    int ret = 0;
    if (x1 == x2) {
      for (int y = y1; y <= y2; ++y) {
        ret += r[x1][y] > 0.0;
      }
    } else if (y1 == y2) {
      for (int x = x1; x <= x2; ++x) {
        ret += r[x][y1] > 0.0;
      }
    } else {
      InitPravac(x1, y1, x2, y2);
      if (y2 > y1) {
        int prev_y = y1;
        int next_y = ceil(GetY(x1 + 1) - 1e-6);
        ret += Count(x1, prev_y, next_y);
        for (int x = x1 + 1; x < x2; ++x) {
          int curr_y = next_y;
          next_y = ceil(GetY(x + 1) - 1e-6);
          ret += Count(x, prev_y, next_y);
          prev_y = curr_y - 1;
        }
        ret += Count(x2, prev_y, next_y);
      } else {
        int prev_y = y1;
        int next_y = floor(GetY(x1 + 1) + 1e-6);
        ret += Count(x1, next_y, prev_y);
        for (int x = x1 + 1; x < x2; ++x) {
          int curr_y = next_y;
          next_y = floor(GetY(x + 1) + 1e-6);
          ret += Count(x, next_y, prev_y);
          prev_y = curr_y + 1;
        }
        ret += Count(x2, next_y, prev_y);
      }
    }
    printf("%d\n", ret);
  }
  return 0;
}
