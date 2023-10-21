#include <bits/stdc++.h>

using namespace std;

const int N = 3005;

char s[N][N];

int c[N][N], g[N][N], n, m, ada[N * N], cnt[N * N];
bool vis[N][N];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

int tot, sz;
set<pair<int, int>> near;

void dfs(int i, int j, int id) {
  if (g[i][j] != -1) return;
  g[i][j] = id;
  tot += c[i][j];
  sz += 1;
  for (int d = 0; d < 4; d++) {
    int pi = i + dx[d];
    int pj = j + dy[d];
    if (!valid(pi, pj)) continue;
    if (s[pi][pj] == 'W') dfs(pi, pj, id);
    if (s[pi][pj] == '.') {
      near.insert(make_pair(pi, pj));
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    memset(c, 0, sizeof(c));
    memset(vis, 0, sizeof(vis));
    memset(g, -1, sizeof(g));

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      scanf("%s", s[i]);
    }
    int all_white = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == 'W') {
          all_white++;
        }
      }
    }
    int now = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == 'W' && g[i][j] == -1) {
          tot = 0; sz = 0;
          near.clear();
          dfs(i, j, now);
          ada[now] = near.size();
          cnt[now] = sz;

          now++;
        }
      }
    }
    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < m; j++) {
    //     printf("%d ", g[i][j]);
    //   }
    //   printf("\n");
    // }
    // for (int i = 0; i < now; i++) printf("%d ", ada[i]); printf("\n");
    // for (int i = 0; i < now; i++) printf("%d ", cnt[i]); printf("\n");
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '.') {
          int cur = 0;
          set<int> cur_g;
          for (int d = 0; d < 4; d++) {
            int pi = i + dx[d];
            int pj = j + dy[d];
            if (!valid(pi, pj)) continue;
            if (s[pi][pj] == 'W') {
              if (ada[g[pi][pj]] == 1) {
                cur_g.insert(g[pi][pj]);
              }
            }
          }
          int cur_tot = 0;
          for (auto it : cur_g) {
            cur_tot += cnt[it];
          }
          if (cur_tot > 0) {
            ans = max(ans, cur_tot);
          }
        }
      }
    }
    printf("Case #%d: %d\n", tt, ans);
    cerr << tt << " done!" << endl;
  } 

  return 0;
}
