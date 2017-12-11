#include <bits/stdc++.h>

using namespace std;

const int inf = 2e9;
int X, Y, Z, A, B, C;

int add_X_Z(int x, int y, int z) {
  vector<pair<int, int>> s;
  s.emplace_back(A * 6, 1);
  s.emplace_back(B * 3, 2);
  s.emplace_back(C * 2, 3);
  sort(s.begin(), s.end());
  int ans = 0;
  for (auto it : s) {
    if (it.second == 1) {
      ans += (x + y + z) * A;
      x = y = z = 0;
    } else if (it.second == 2) {
      int del = min(x, z);
      ans += del * B;
      x -= del;
      z -= del;
    } else {
      int del = min(x, min(y, z));
      ans += del * C;
      x -= del;
      y -= del;
      z -= del;
    }
  }
  assert(x == 0 && y == 0 && z == 0);
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
