#include <bits/stdc++.h>

using namespace std;

const int N = 505;
const int GROUP = 25;
const long long mod = 1e9 + 7;

long long bef[N][GROUP], aft[N][GROUP];
char junk[N];
int a[N];

void add(long long& at, long long val) {
  at += val;
  at %= mod;
}

int main() {
  int n, K;
  scanf("%s %d %d", junk, &n, &K);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }

  bef[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      for (int k = 1; k < GROUP; k++) {
        add(bef[j][k], bef[i-1][k - 1]);
      }
    }
    for (int k = 0; k < GROUP; k++) {
      add(bef[i][k], bef[i-1][k]);
    }
  }

  aft[n + 1][0] = 1;
  for (int i = n; i >= 1; i--) {
    for (int j = i; j >= 1; j--) {
      for (int k = 1; k < GROUP; k++) {
        add(aft[j][k], aft[i+1][k-1]);
      }
    }
    for (int k = 0; k < GROUP; k++) {
      add(aft[i][k], aft[i+1][k]);
    }
  }

  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int now = a[i];
    for (int j = i; j <= n; j++) {
      now = __gcd(now, a[j]);
      for (int k = 0; k < K; k++) {
        long long ways = (bef[i-1][k] * aft[j+1][K-1-k]) % mod;
        ans += now * ways;
        ans %= mod;
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
