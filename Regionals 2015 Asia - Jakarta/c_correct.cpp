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
    printf("Case #%d:\n", tt);
    while (q--) {
      int u, y;
      scanf("%d %d", &u, &y);
      int cntu = 0;
      int cnt_all = 0;
      int ans = 1;
      for (int i = 1; i <= n; i++) {
        cnt_all++;
        if (a[i] == u) {
          cntu++;
          if (cnt_all >= b[y] && cntu >= y) {
            cntu = 0;
            cnt_all = 0;
            ans++;
          }
        }
      }
      if (cnt_all == 0) ans--;
      printf("%d\n", ans);
    }
    
  }

  return 0;
}
