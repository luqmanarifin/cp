#include <bits/stdc++.h>

using namespace std;

const int inf = 2e9;
int X, Y, Z, A, B, C;

int dua(int x, int y, int z) {
  if (2 * A <= B) return (x + y + z) * A;
  vector<int> p = {x, y, z};
  sort(p.begin(), p.end());
  x = p[0];
  y = p[1];
  z = p[2];
  
  int b = 0;
  
  int del = min(x, z - y);
  b += del;
  x -= del;
  z -= del;
  
  b += x;
  z -= x / 2;
  y -= x / 2 + x % 2;
  x = 0;
  
  del = min(y, z);
  b += del;
  y -= del;
  z -= del;
  
  return b * B + (x + y + z) * A;
}

int solve(int x, int y, int z) {
  int ans = inf;
  
  int l = 0, r = min(x, min(y, z)) / 2;
  while (r - l > 3) {
    int lf = l + (r - l) / 3;
    int rf = r - (r - l) / 3;
    if (dua(x - 2*lf, y - 2*lf, z - 2*lf) + 2*lf * C < dua(x - 2*rf, y - 2*rf, z - 2*rf) + 2*rf * C) {
      r = rf;
    } else {
      l = lf;
    }
  }
  for (int i = l; i <= r; i++) ans = min(ans, dua(x - 2*i, y - 2*i, z - 2*i) + 2*i * C);
  
  l = 0, r = (min(x, min(y, z)) - 1) / 2;
  while (r - l > 3) {
    int lf = l + (r - l) / 3;
    int rf = r - (r - l) / 3;
    if (dua(x - 2*lf-1, y - 2*lf-1, z - 2*lf-1) + (2*lf+1) * C < dua(x - 2*rf-1, y - 2*rf-1, z - 2*rf-1) + (2*rf+1) * C) {
      r = rf;
    } else {
      l = lf;
    }
  }
  for (int i = l; i <= r; i++) ans = min(ans, dua(x - 2*i-1, y - 2*i-1, z - 2*i-1) + (2*i+1) * C);
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d %d %d %d", &X, &Y, &Z, &A, &B, &C);
    printf("%d\n", solve(X, Y, Z));
  }
  return 0;
}
