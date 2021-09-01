#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int sum[N], n;
char s[N];

long long solve(long long l, long long r) {
  // printf("%lld %lld\n", l, r);
  if (l / n == r / n) {
    l %= n;
    r %= n;

    return sum[r] - (l? sum[l - 1] : 0);
  }
  if (l / n + 1 == r / n) {
    long long p = r / n * n;
    return solve(l, p - 1) + solve(p, r);
  } else {
    long long full = r / n - l / n - 1;
    long long pl = (l / n + 1) * n - 1;
    long long pr = r / n * n;
    return full * sum[n - 1] + solve(l, pl) + solve(pr, r);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    long long l, r;
    scanf("%s %lld %lld", s, &l, &r);
    l--; r--;
    n = strlen(s);
    for (int i = 0; i < n; i++) {
      sum[i] = (s[i] == 'B');
      if (i) sum[i] += sum[i - 1];
    }
    printf("Case #%d: %lld\n", tt, solve(l, r));
  }
  return 0;
}
