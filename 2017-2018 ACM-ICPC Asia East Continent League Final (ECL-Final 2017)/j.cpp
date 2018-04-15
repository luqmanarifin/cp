#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
long long a[N], d[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    memset(a, 0, sizeof(a));
    memset(d, 0, sizeof(d));
    
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%lld", a + i);
    }
    printf("Case #%d: ", tt);
    for (int i = 1; i <= n + 1; i++) {
      d[i] = a[i] - a[i - 1];
    }
    bool ok = 1;
    priority_queue<pair<int, long long>> pq;    // -idx / berapa
    for (int i = 1; i <= n + 1; i++) {
      if (d[i] > 0) {
        pq.emplace(-i, d[i]);
      } else if (d[i] < 0) {
        long long need = -d[i];
        while (need) {
          int idx; long long much;
          tie(idx, much) = pq.top(); pq.pop();
          idx = -idx;
          //~ printf("iterasi %d need %lld nemu %lld di %d\n", i, need, much, idx);
          if (i - idx < 3) {
            break;
          }
          long long del = min(need, much);
          need -= del;
          much -= del;
          if (much) {
            pq.emplace(-idx, much);
          }
        }
        if (need) {
          ok = 0;
          break;
        }
      }
    }
    puts(ok? "Yes": "No");
  }

  return 0;
}
