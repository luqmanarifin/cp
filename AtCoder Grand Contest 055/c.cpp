#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

long long mod;

long long c[N][N];

int main() {
  int n, m;
  scanf("%d %d %lld", &n, &m, &mod);

  for (int i = 1; i < N; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; j++) {
      c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
    }
  }
  long long ans = 0;
  for (int base = 2; base <= m; base++) {
    if (n <= 4) {
      ans++;
    } else if (n <= 6) {
      if (base != n - 2) {
        ans++;
      }
    } else {
      if (base != n - 2 && base != n - 3) {
        ans++;
      }
    }
    if (base + 1 <= m) {
      int fill = n - 1 - base;
      if (fill == 1) {
        ans += 2 * n - 1;
      } else {
        for (int i = fill; i < n; i++) {
          ans += c[n][i];
          ans %= mod;
        }
      }
    }
  }
  cout << ans % mod << endl;
  return 0;
}
