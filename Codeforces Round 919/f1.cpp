#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> b;
vector<vector<char>> s;
vector<vector<bool>> f, g;
vector<pair<int, int>> isle;

int x4[] = {0, 0, -1, 1};
int y4[] = {1, -1, 0, 0};
int x8[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int y8[] = {1, 1, 1, 0, -1, -1, -1, 0};
int n, m;

bool valid(int i, int j) {
  return 1 <= i && i <= n && 1 <= j && j <= m;
}

bool is_sea(int x, int y) {
  return s[x][y] == '.' || s[x][y] == 'v';
}

void dfs_can(int x, int y, int dis) {
  for (int i = 0; i < 4; i++) {
    int dx = x + x4[i];
    int dy = y + y4[i];
    if (!valid(dx, dy) || !is_sea(dx, dy)) continue;
    if (f[dx][dy]) continue;
    if (b[dx][dy] >= dis) {
      f[dx][dy] = 1;
      dfs_can(dx, dy, dis);
    }
  }
}

bool dfs_isle(int x, int y) {
  for (int i = 0; i < 8; i++) {
    int dx = x + x8[i];
    int dy = y + y8[i];
    if (!valid(dx, dy)) return 1;
    if (f[dx][dy]) continue;
    if (g[dx][dy]) continue;
    g[dx][dy] = 1;
    if (dfs_isle(dx, dy)) return 1;
  }
  return 0;
}

bool can(int x, int y, int dis) {
  if (b[x][y] < dis) return 0;
  f.assign(n + 2, vector<bool>(m + 2, false));
  f[x][y] = 1;
  dfs_can(x, y, dis);

  g.assign(n + 2, vector<bool>(m + 2, false));
  for (auto it : isle) {
    if (g[it.first][it.second]) continue;
    g[it.first][it.second] = 1;
    if (dfs_isle(it.first, it.second)) return 0;
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int q;
  cin >> n >> m >> q;

  b.assign(n + 2, vector<int>(m + 2, -1));
  s.assign(n + 2, vector<char>(m + 2));

  vector<pair<int, int>> vols;
  for (int i = 1; i <= n; i++) {
    string buf;
    cin >> buf;
    for (int j = 1; j <= m; j++) {
      s[i][j] = buf[j-1];
      if (s[i][j] == 'v') {
        vols.emplace_back(i, j);
      }
      if (s[i][j] == '#') {
        isle.emplace_back(i, j);
      }
    }
  }
  queue<pair<int, int>> que;
  for (auto it : vols) {
    b[it.first][it.second] = 0;
    que.push(make_pair(it.first, it.second));
  }
  while (!que.empty()) {
    int x, y;
    tie(x, y) = que.front();
    que.pop();
    for (int i = 0; i < 4; i++) {
      int dx = x + x4[i];
      int dy = y + y4[i];
      if (valid(dx, dy) && b[dx][dy] == -1) {
        b[dx][dy] = b[x][y] + 1;
        que.push(make_pair(dx, dy));
      }
    }
  }
  while (q--) {
    int x, y;
    cin >> x >> y;
    int l = 0, r = n + m;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (can(x, y, mid)) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    cout << l << '\n';
  }

  return 0;
}
