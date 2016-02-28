#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e6 + 5;
const int mod = 1e9 + 7;

long long a[N], s[N], d[N];

long long get(int l, int r) {
  return (s[r] - s[l - 1] + mod) % mod;
}

main() {
  int n, k;
  scanf("%lld %lld", &n, &k);
  for(int i = 1; i <= n; i++) {
    scanf("%lld", a + i);
    s[i] = (s[i - 1] + a[i]) % mod;
  }
  for(int i = 1; i <= k; i++) {
    d[1] = (d[1] + (2*i-1)*a[i]) % mod;
  }
  for(int i = 2; i + k <= n; i++) {
    d[i] = d[i - 1] - a[i - 1] - 2*get(i, i + k - 2) + (2*k-1)*a[i + k - 1];
    d[i] %= mod;
    if(d[i] < 0) d[i] += mod;
  }
  for(int i = 1; i + k <= n; i++) {
    d[i] -= (k * k % mod) * a[i + k];
    d[i] %= mod;
    if(d[i] < 0) d[i] += mod;
    //printf("%d %lld\n", i, d[i]);
  }
  long long now = 0;
  for(int i = 1; i <= k; i++) {
    now += (1LL * i * i % mod) * a[i];
    now %= mod;
  }
  for(int i = 1; i <= n - k + 1; i++) {
    if(i > 1) printf(" ");
    printf("%lld", now);
    now = (now - d[i] + mod) % mod;
  }
  printf("\n");
  return 0;
}
