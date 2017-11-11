#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int inf = 1e9;

int a[N], d[N], p[N];

int main() {
  int k, n, m;
  scanf("%d %d", &k, &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  a[n]--;
  scanf("%d", &m);
  int done = 0;
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", d + i, p + i);
    if (p[i] == n) done++;
  }
  vector<int> ans;
  while (done < m) {
    bool change = 0;
    for (int i = 1; i <= m; i++) {
      if (p[i] == n) continue;
      while (1) {
        if (p[i] == n) {
          done++;
          break;
        }
        
        bool ok = 1;
        int closest = inf;
        if (i + 1 <= m && p[i + 1] != n) {
          int cur = abs(a[p[i] + 1] - a[p[i + 1]]);
          ok &= (cur >= d[i]);
          ok &= (cur >= d[i + 1]);
          closest = min(closest, cur);
        }
        if (i - 1 >= 1) {
          int cur = abs(a[p[i] + 1] - a[p[i - 1]]);
          ok &= (cur >= d[i]);
          ok &= (cur >= d[i - 1]);
          closest = min(closest, cur);
        }
        if (closest != inf) {
          if (closest > k) ok = 0;
        }
        if (ok) {
          change = 1;
          ans.push_back(i);
          p[i]++;
        } else {
          break;
        }
      }
    }
    //printf("%d %d\n", p[1], p[2]);
    if (!change) {
      puts("impossible");
      return 0;
    }
  }
  for (int i = 0; i < ans.size(); i++) printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);
  return 0;
}
