#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e6 + 5;
const int magic = 80000;
const long long inf = 1e18;

bool is[N];
int prime[magic];

int a[N], cnt[N];
long long s[N];

main() {
  int sz = 0;
  for (int i = 2; i < N; i++) {
    if (!is[i]) {
      prime[sz++] = i;
      for (long long j = 1LL * i * i; j < N; j += i) {
        is[j] = 1;
      }
    }
  }
  cout << sz << endl;
  int n;
  long long x, y;
  scanf("%I64d %I64d %I64d", &n, &x, &y);
  long long k = x / y + 1;
  for (int i = 0; i < n; i++) {
    scanf("%I64d", a + i);
    cnt[a[i]]++;
  }
  for (int i = 1; i < N; i++) {
    cnt[i] += cnt[i - 1];
    s[i] = s[i - 1] + cnt[i - 1];
  }
  
  long long ans = inf;
  for (int j = 0; j < sz; j++) {
    long long cur = 0;
    for (int i = prime[j]; i < N; i += prime[j]) {
      if (k < prime[j]) {
        cur += (cnt[i-k] - cnt[i-prime[j]]) * x;
        cur += (s[i] - s[i-k] - k*cnt[i-k]) * y;
      } else {
        cur += (s[i] - s[i-prime[j]] - prime[j]*cnt[i-prime[j]]) * y;
      }
    }
    ans = min(ans, cur);
  }
  cout << ans << endl;
  return 0;
}