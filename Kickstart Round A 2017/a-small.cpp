#include <bits/stdc++.h>

using namespace std;

const int N = 11;
const int mod = 1e9 + 7;

int ans[N][N];
int n, m;

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

int main() {
  for (n = 2; n < N; n++) {
    for (m = 2; m < N; m++) {
      ans[n][m] = ans[n][m - 1];
      for (int i = 0; i < n; i++) {
        for (int j = i; j >= 0; j--) {
          int k = 1;
          int bi = j;
          int bj = k;
          int ci = i + k;
          int cj = i - j;
          int di = j + k;
          int dj = k + i - j;
          if (!valid(bi, bj) || !valid(ci, cj) || !valid(di, dj)) break;
          int l = 1, r = m;
          while (l < r) {
            int k = (l + r + 1) >> 1;
            bi = j;
            bj = k;
            ci = i + k;
            cj = i - j;
            di = j + k;
            dj = k + i - j;
            if (!valid(bi, bj) || !valid(ci, cj) || !valid(di, dj)) {
              r = k - 1;
            } else {
              l = k;
            }
          }
          ans[n][m] += l;
        }
      }
      ans[n][m] %= mod;
      printf("%d %d: %d\n", n, m, ans[n][m]);
    }
  }
  cerr << "done brute" << endl;
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    scanf("%d %d", &n, &m);
    printf("Case #%d: %d\n", tt, ans[n][m]);
  }
  return 0;
}
