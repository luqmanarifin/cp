#include <bits/stdc++.h>

using namespace std;

const int N = 505;
const int mod = 1e9 + 7;

long long c[N][N];
long long fact[N];

int main() {
  fact[0] = 1;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N && j <= i; j++) {
      if(j == 0 || j == i) {
        c[i][j] = 1;
      } else {
        c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
      }
    }
    if(i > 0) {
      fact[i] = fact[i - 1] * i % mod;
    }
  }
  
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int n, k, p;
    scanf("%d %d %d", &n, &k, &p);
    long long ans = 0;
    int rem = n - p;
    for(int i = k + 1; i <= n; i++) {
      int len = i - k - 1;
      for(int j = p + 1; j <= n; j++) {
        int non = n - len - 2;
        ans += c[j - 2][len] * fact[non];
        ans %= mod;
      }
    }
    ans += c[p - 1][n - k] * fact[k - 1];
    ans %= mod;
    printf("Case #%d: %d\n", tt, (int) ans);
  }
  
  return 0;
}
