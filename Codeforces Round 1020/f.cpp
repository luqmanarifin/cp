#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char s[N];
long long u[N], d[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d %s", &n, s);
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        u[i] = d[i] = 0;
      } else {
        u[i] = i;
        d[i] = n - i - 1;
      }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') continue;
      int j = i;
      while (j + 1 < n && s[j + 1] == s[j]) j++;
      long long sum_d = 0, sum_u = 0;
      for (int k = i; k <= j; k++) {
        sum_d += d[k];
        sum_u += u[k];
      }
      for (int k = i; k <= j; k++) {
        d[k] = sum_d;
        u[k] = sum_u;
      }
      ans = max(ans, sum_d);
      ans = max(ans, sum_u);
      i = j;
    }
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        long long cur = 1 + (i + 1 < n? u[i + 1] : 0) + (i - 1 >= 0? d[i - 1] : 0);
        ans = max(ans, cur);
      }
    }
    printf("%lld\n", ans);
  }

  return 0;
}
