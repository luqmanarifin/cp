#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 9;
const int N = 5e4 + 5;

int a[N], b[N], l[N], r[N];

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int n, m, d;
    scanf("%d %d %d", &n, &m, &d);
    for(int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    for(int i = 0; i < m; i++) {
      scanf("%d", b + i);
    }
    for(int i = 0; i < m; i++) {
      l[i] = lower_bound(a, a + n, b[i] - d + 1) - a;
      r[i] = lower_bound(a, a + n, b[i] + d) - a;
    }
    vector<int> a;
    a.assign(r[0] - l[0] + 1, 1);
    for(int i = 1; i < m; i++) {
      vector<int> b;
      b.resize(r[i] - l[i] + 1);
      for(int i = 1; i < a.size(); i++) {
        a[i] = (a[i] + a[i - 1]) % mod;
      }
      int pa = l[i - 1];
      int ia = 0;
      int pb = l[i];
      int ib = 0;
      while(pa < pb && ia < a.size()) {
        pa++; ia++;
      }
      for(; pa <= r[i - 1] && ia < a.size() && pb <= r[i] && ib < b.size(); pa++, ia++, pb++, ib++) {
        b[ib] = a[ia];
      }
      for(; ib < b.size(); ib++) {
        b[ib] = a.back();
      }
      a = b;
    }
    int ans = 0;
    for(auto it : a) {
      ans = (ans + it) % mod;
    }
    printf("Case #%d: %d\n", tt, ans);
  }
  return 0;
}
