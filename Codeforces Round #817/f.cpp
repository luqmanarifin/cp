#include <bits/stdc++.h>

using namespace std;

const int N = 55;

char s[N][N];
int n, m;

int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool vis[N][N];
vector<pair<int, int>> st;

bool valid(int x, int y) {
  return 0 <= x && x < n && 0 <= y && y < m;
}

void dfs(int x, int y) {
  vis[x][y] = 1;
  st.emplace_back(x, y);
  for (int d = 0; d < 8; d++) {
    int px = x + dx[d];
    int py = y + dy[d];
    if (!valid(px, py)) continue;
    if (s[px][py] == '*' && !vis[px][py]) {
      dfs(px, py);
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(vis, 0, sizeof(vis));

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", s[i]);

    bool good = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] != '*') continue;
        if (vis[i][j]) continue;
        st.clear();
        dfs(i, j);
        if (st.size() != 3) {
          good = 0;
          break;
        }
        bool found = 0;
        for (int x = 0; x < st.size(); x++) {
          vector<pair<int, int>> v;
          v.emplace_back(abs(st[x].first - st[(x+1)%3].first), abs(st[x].second - st[(x+1)%3].second));
          v.emplace_back(abs(st[x].first - st[(x+2)%3].first), abs(st[x].second - st[(x+2)%3].second));
          sort(v.begin(), v.end());
          if (v[0] == make_pair(0, 1) && v[1] == make_pair(1, 0)) {
            found = 1;
            break;
          }
        }
        if (!found) {
          good = 0;
          break;
        }
      }
    }
    puts(good? "YES" : "NO");
  }

  return 0;
}
