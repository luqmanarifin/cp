#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e6 + 5, mod = 1e9 + 7;
long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1) r = r * b % mod;
  return r;
}
 
int a[N], n, k;
int b[N], cnt;
long long dp[N];
 
void add(int x) {
  if (x <= k) {
    if (b[x] == 0) cnt++;
    b[x]++;
  }
}
void rem(int x) {
  if (x <= k) {
    b[x]--;
    if (b[x] == 0) cnt--;
  }
}
 
int main() {
  scanf("%d %d", &n, &k);
  cnt = 0;
  for (int i = 1; i <= n; i++)
    scanf("%d", a+i);
  if (k > n) {
    printf("%lld\n", powmod(2, n-1));
    return 0;
  }
  dp[0] = 1;
  long long sum = 0;
  int l = 1;
  for (int i = 1; i <= n; i++) {
    add(a[i]);
    sum = (sum + dp[i-1]) % mod;
    while (l < i && cnt >= k+1) {
      rem(a[l]);
      sum = (sum + mod - dp[l-1]) % mod;
      l++;
    }
    if (sum < 0) sum += mod;
    dp[i] = sum;
  }
  printf("%lld\n", dp[n]);
  return 0;
} 