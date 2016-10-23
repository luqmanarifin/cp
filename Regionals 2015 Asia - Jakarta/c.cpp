#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> all, pos[N];
map<pair<int, int>, int> cache;

int a[N], b[N];

int id(int val) { 
  return lower_bound(all.begin(), all.end(), val) - all.begin();
}

bool ada(int v) {
  return binary_search(all.begin(), all.end(), v);
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    cache.clear();
    all.clear();
    for (int i = 0; i < N; i++) pos[i].clear();
    
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      all.push_back(a[i]);
    }
    sort(all.begin(), all.end());
    all.resize(distance(all.begin(), unique(all.begin(), all.end())));
    for (int i = 1; i <= n; i++) {
      int d = id(a[i]);
      pos[d].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
      scanf("%d", b + i);
    }
    printf("Case #%d: \n", tt);
    while (q--) {
      int u, y;
      scanf("%d %d", &u, &y);
      if (!ada(u)) {
        puts("1");
        continue;
      }
      if (cache.count({u, y})) {
        printf("%d\n", cache[{u, y}]);
        continue;
      }
      int num = u;
      u = id(u);
      int now = -1;
      int ans = 0;
      int asli = 0;
      while (now < (int) pos[u].size()) {
        int at = lower_bound(pos[u].begin(), pos[u].end(), asli + b[y]) - pos[u].begin();
        if (now + y < (int) pos[u].size()) {
          at = max(at, now + y);
        } else {
          at = N;
        }
        if (at < (int) pos[u].size()) {
          ans++;
          asli = pos[u][at];
        }
        now = at;
      }
      if (asli != n) ans++;
      printf("%d\n", ans);
      cache[{num, y}] = ans;
    }
    
  }

  return 0;
}
