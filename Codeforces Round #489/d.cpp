#include <bits/stdc++.h>

using namespace std;

const long long inf = 4e18;
const int N = 2e5 + 5;

long long mul(long long a, long long b) {
  if (inf / a < b) return inf;
  return a * b;
}

long long a[N], s[N];
int nx[N];

int main() {
  int n; long long k;
  scanf("%d %lld", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", a + i);
    s[i] = s[i - 1] + a[i];
  }
  nx[n + 1] = n + 1;
  for (int i = n; i >= 1; i--) {
    nx[i] = nx[i + 1];
    if (a[i] > 1) nx[i] = i;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int st = i;
    long long now = a[i];
    while (now < inf && st <= n) {
      int en = nx[st + 1] - 1;
      if (now % k == 0) {
        long long val = s[i - 1] + now / k;
        int p = lower_bound(s + 1, s + 1 + n, val) - s;
        //printf("%d: %d %d: %lld\n", i, st, en, val);
        if (st <= p && p <= en && s[p] == val) ans++;
      }
      st = en + 1;
      now = mul(now, a[st]);
    }
  }
  cout << ans << endl;
  return 0;
}
