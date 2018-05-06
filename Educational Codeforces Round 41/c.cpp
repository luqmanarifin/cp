
#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[5][N][N];
int c[5][2];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%s", s[i][j]);
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        int asli = (j + k) % 2;
        if (s[i][j][k] - '0' != asli) {
          c[i][0]++;
        } else {
          c[i][1]++;
        }
      } 
    }
  }
  int ans = 1e9;
  for (int mask = 0; mask < (1 << 4); mask++) {
    if (__builtin_popcount(mask) != 2) continue;
    int cur = 0;
    for (int i = 0; i < 4; i++) {
      if (mask & (1 << i)) {
        cur += c[i][1];
      } else {
        cur += c[i][0];
      }
    }
    ans = min(ans, cur);
  }
  cout << ans << endl;
  return 0;
}
