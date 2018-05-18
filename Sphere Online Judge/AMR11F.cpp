#include <bits/stdc++.h>

using namespace std;

const int N = 305;
const int inf = 1e9;

set<int> fl[N];
pair<int, int> imp[N];  // [ID]: tower -> fl
map<int, int> to_id[N];    // [tower]: fl -> id
int dist[N][N];

void upd(int& at, int val) {
  at = min(at, val);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < N; i++) {
      fl[i].clear();
      to_id[i].clear();
    }
    
    int n, f, m;
    scanf("%d %d %d", &n, &f, &m);
    vector<tuple<int, int, int, int, int>> bridges;
    for (int i = 0; i < m; i++) {
      int a, b, c, d, e;
      scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
      bridges.emplace_back(a, b, c, d, e);
      fl[a].insert(b);
      fl[c].insert(d);
    }
    for (int i = 1; i <= n; i++) {
      fl[i].insert(1);
    }
    int pt = 0;
    for (int i = 1; i <= n; i++) {
      for (auto f : fl[i]) {
        int id = pt++;
        imp[id] = {i, f};
        to_id[i][f] = id;
      }
    }
    for (int i = 0; i < pt; i++) {
      for (int j = 0; j < pt; j++) {
        dist[i][j] = inf;
      }
      dist[i][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      int j = (i == n? 1 : i + 1);
      upd(dist[to_id[i][1]][to_id[j][1]], 1);
      upd(dist[to_id[j][1]][to_id[i][1]], 1);
      int bef = -1;
      for (auto it : fl[i]) {
        if (bef != -1) {
          upd(dist[to_id[i][it]][to_id[i][bef]], abs(it - bef));
          upd(dist[to_id[i][bef]][to_id[i][it]], abs(it - bef));
        }
        bef = it;
      }
    }
    for (auto it : bridges) {
      int a, b, c, d, e;
      tie(a, b, c, d, e) = it;
      upd(dist[to_id[a][b]][to_id[c][d]], e);
      upd(dist[to_id[c][d]][to_id[a][b]], e);
    }
    for (int k = 0; k < pt; k++) {
      for (int i = 0; i < pt; i++) {
        for (int j = 0; j < pt; j++) {
          upd(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
    /*
    for (int i = 0; i < pt; i++) printf("%d: %d %d\n", i, imp[i].first, imp[i].second);
    for (int i = 0; i < pt; i++) {
      for (int j = 0; j < pt; j++) {
        printf("%d %d: %d\n", i, j, dist[i][j]);
      }
    }
    */
    
    int q;
    scanf("%d", &q);
    while (q--) {
      int a, b, c, d;
      scanf("%d %d %d %d", &a, &b, &c, &d);
      vector<tuple<int, int, int>> lef, rig;
      auto it = fl[a].lower_bound(b);
      if (it != fl[a].end()) {
        lef.emplace_back(a, *it, abs(*it - b));
      }
      if (it != fl[a].begin()) {
        it--;
        lef.emplace_back(a, *it, abs(*it - b));
      }
      
      it = fl[c].lower_bound(d);
      if (it != fl[c].end()) {
        rig.emplace_back(c, *it, abs(*it - d));
      }
      if (it != fl[c].begin()) {
        it--;
        rig.emplace_back(c, *it, abs(*it - d));
      }
      int ans = inf;
      if (a == c) {
        ans = min(ans, abs(b - d));
      }
      for (auto l : lef) {
        for (auto r : rig) {
          int a, b, c, d, addl, addr;
          tie(a, b, addl) = l;
          tie(c, d, addr) = r;
          upd(ans, addl + addr + dist[to_id[a][b]][to_id[c][d]]);
        }
      }
      printf("%d\n", ans);
    }
  }

  return 0;
}
