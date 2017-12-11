#include <bits/stdc++.h>

using namespace std;

const int inf = 2e9;
int X, Y, Z, A, B, C;

int solve(int x, int y, int z) {
  int ret = 0;
  if (3 * A > C) {
    int del = min(x, min(y, z));
    ret += del * C;
    x -= del;
    y -= del;
    z -= del;
  }
  ret += (x + y + z) * A;
  return ret;
}

int add_X_Z(int x, int y, int z) {
  int l = 0, r = min(x, z);
  while (r - l > 3) {
    int lf = l + (r - l) / 3;
    int rf = r - (r - l) / 3;
    if (solve(x - lf, y, z - lf) + lf * B < solve(x - rf, y, z - rf) + rf * B) {
      r = rf;
    } else {
      l = lf;
    }
  }
  int ans = inf;
  for (int i = l; i <= r; i++) ans = min(ans, solve(x - i, y, z - i) + i * B);
  return ans;
}

int add_Y_Z(int x, int y, int z) {
  int l = 0, r = min(y, z);
  while (r - l > 3) {
    int lf = l + (r - l) / 3;
    int rf = r - (r - l) / 3;
    if (add_X_Z(x, y - lf, z - lf) + lf * B < add_X_Z(x, y - rf, z - rf) + rf * B) {
      r = rf;
    } else {
      l = lf;
    }
  }
  int ans = inf;
  for (int i = l; i <= r; i++) ans = min(ans, add_X_Z(x, y - i, z - i) + i * B);
  return ans;
}

int add_X_Y(int x, int y, int z) {
  int l = 0, r = min(x, y);
  while (r - l > 3) {
    int lf = l + (r - l) / 3;
    int rf = r - (r - l) / 3;
    if (add_Y_Z(x - lf, y - lf, z) + lf * B < add_Y_Z(x - rf, y - rf, z) + rf * B) {
      r = rf;
    } else {
      l = lf;
    }
  }
  int ans = inf;
  for (int i = l; i <= r; i++) ans = min(ans, add_Y_Z(x - i, y - i, z) + i * B);
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d %d %d %d", &X, &Y, &Z, &A, &B, &C);
    printf("%d\n", add_X_Y(X, Y, Z));
  }
  return 0;
}
