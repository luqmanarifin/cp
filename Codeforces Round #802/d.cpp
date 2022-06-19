#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long a[N], suf[N];
long long need[N], rem[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", a + i);

  for (int i = 1; i <= n; i++) {
    long long time_now = need[i - 1];
    long long cur_fill = rem[i - 1] + time_now;
    if (cur_fill < a[i]) {
      long long sisa = a[i] - cur_fill;
      long long time_add = (sisa + i - 1) / i;
      need[i] = time_now + time_add;
      rem[i] = time_add * i - sisa;
    } else {
      need[i] = time_now;
      rem[i] = cur_fill - a[i];
    }
    // printf("%d: need %lld rem %lld\n", i, need[i], rem[i]);
  }
  suf[n + 1] = 0;
  for (int i = n; i >= 1; i--) suf[i] = suf[i + 1] + a[i];

  vector<long long> p;
  for (int i = 1; i <= n; i++) {
    long long sisa = max(0LL, suf[i + 1] - rem[i]);
    long long time_add = (sisa + i - 1) / i;
    p.push_back(need[i] + time_add);
    // printf("use %d need %lld time add %lld\n", i, need[i], time_add);
  }
  sort(p.begin(), p.end());

  int q;
  scanf("%d", &q);
  while (q--) {
    int v;
    scanf("%d", &v);
    int idx = upper_bound(p.begin(), p.end(), v) - p.begin() - 1;
    if (idx < 0) {
      printf("-1\n");
    } else {
      printf("%d\n", n - idx);
    }      
  }

  return 0;
}
