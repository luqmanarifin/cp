#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
      a[i] = (1 << a[i]);
    }
    sort(a, a + n);
    reverse(a, a + n);
    priority_queue<pair<int, int>> pq;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (pq.empty() || pq.top().first < a[i]) {
        pq.emplace(m, m);
        ans++;
      }
      int u, v;
      tie(u, v) = pq.top();
      pq.pop();
      if (u > a[i]) {
        int l = min(u - a[i], a[i]);
        int r = max(u - a[i], a[i]);
        pq.emplace(l, r);
      }
      if (v > a[i]) {
        int l = min(v - a[i], a[i]);
        int r = max(v - a[i], a[i]);
        pq.emplace(l, r);
      }
      if (u > a[i] && v > a[i]) {
        int l = min(u - a[i], v - a[i]);
        int r = max(u - a[i], v - a[i]);
        pq.emplace(l, r);
      }      
    }
    printf("%d\n", ans);
  }

  return 0;
}
