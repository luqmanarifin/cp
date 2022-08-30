#include <bits/stdc++.h>

using namespace std;

const int N = 3005;

int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};
int n, m;

char s[N][N];

vector<vector<bool>> vis, cant;
vector<vector<int>> c;

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    scanf("%d %d", &n, &m);
    vis.assign(n, vector<bool>(m, 0));
    cant.assign(n, vector<bool>(m, 0));
    c.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
      scanf("%s", s[i]);
    }

    // num edge - x - y
    priority_queue<tuple<int, int, int>> pq;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '#') continue;
        int cnt = 0;
        for (int d = 0; d < 4; d++) {
          int p = i + dx[d];
          int q = j + dy[d];
          if (!valid(p, q)) continue;
          if (s[p][q] == '#') continue;
          cnt++;
        }
        c[i][j] = cnt;
        if (cnt < 2) pq.emplace(-cnt, i, j);
      }
    }
    while (!pq.empty()) {
      int cur, x, y;
      tie(cur, x, y) = pq.top();
      pq.pop();
      cur = -cur;
      if (cant[x][y]) continue;

      cant[x][y] = 1;
      for (int i = 0; i < 4; i++) {
        int p = x + dx[i];
        int q = y + dy[i];
        if (!valid(p, q)) continue;
        if (s[p][q] == '#') continue;
        if (cant[p][q]) continue;
        c[p][q]--;
        if (c[p][q] < 2) {
          pq.emplace(-c[p][q], p, q);
        }
      }
    }
    bool ok = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '#') continue;
        if (cant[i][j]) {
          if (s[i][j] == '^') {
            ok = 0;
          }
        } else {
          s[i][j] = '^';
        }
      }
    }
    printf("Case #%d: %s\n", tt, ok? "Possible" : "Impossible");
    if (ok) {
      for (int i = 0; i < n; i++) printf("%s\n", s[i]);
    }
  }

  return 0;
}
