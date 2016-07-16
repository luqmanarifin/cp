#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int inf = 1e9;

vector<pair<int, int>> edges[11];
int da[N][N], db[N][N];
int a[N][N], n, m;

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

void bfs(int sa, int sb, int d[N][N], int k) {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      d[i][j] = inf;
    }
  }
  queue<pair<int, int>> q;
  d[sa][sb] = 0;
  q.emplace(sa, sb);
  while(!q.empty()) {
    tie(sa, sb) = q.front();
    int cost = d[sa][sb];
    q.pop();
    for(auto it : edges[k]) {
      int ta = sa + it.first;
      int tb = sb + it.second;
      if(valid(ta, tb) && cost + 1 < d[ta][tb] && a[ta][tb] == 0) {
        d[ta][tb] = cost + 1;
        q.emplace(ta, tb);
      }
    }
  }
}

int main() {
  for(int i = -10; i <= 10; i++) {
    for(int j = -10; j <= 10; j++) {
      int d = abs(i) + abs(j);
      for(int k = d; k <= 10; k++) {
        edges[k].emplace_back(i, j);
      }
    }
  }
  int t;
  scanf("%d", &t);
  while(t--) {
    int k0, k1;
    scanf("%d %d %d %d", &n, &m, &k0, &k1);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    bfs(0, 0, da, k0);
    bfs(0, m - 1, db, k1);
    int ans = inf;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        ans = min(ans, max(da[i][j], db[i][j]));
      }
    }
    if(ans == inf) ans = -1;
    printf("%d\n", ans);
  }

  return 0;
}
