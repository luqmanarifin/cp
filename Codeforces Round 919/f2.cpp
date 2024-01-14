#include <bits/stdc++.h>

using namespace std;

const int N = 6e5 + 5;

vector<vector<int>> b;
vector<vector<char>> s;
vector<vector<int>> ans;
int par[N];
set<int> el[N];

int x4[] = {0, 0, -1, 1};
int y4[] = {1, -1, 0, 0};
int n, m, px, py;

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

bool is_sea(int x, int y) {
  return s[x][y] == '.' || s[x][y] == 'v';
}

int encode(int x, int y, int c) {
  return x * m + y + c * n * m;
}

tuple<int, int, int> decode(int val) {
  int c = val / (n * m);
  val %= (n * m);
  int x = val / m;
  int y = val % m;
  return make_tuple(x, y, c);
}

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}

void merge(int u, int v, int when) {
  u = find(u); v = find(v);
  if (u == v) return;
  if (el[u].size() > el[v].size()) swap(u, v);
  for (auto it : el[u]) {
    int x, y, c;
    tie(x, y, c) = decode(it);
    auto jt = encode(x, y, c ^ 1);
    if (el[v].count(jt)) {
      ans[x][y] = when;
      el[v].erase(jt);
    } else {
      el[v].insert(it);
    }
  }
  par[u] = v;
}

int calc(pair<int, int> x, pair<int, int> y) {
  if (x > y) swap(x, y);
  return x.first == px && y.first == px + 1 && x.second > py;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  for (int i = 0; i < N; i++) {
    par[i] = i;
    el[i].insert(i);
  }

  int q;
  cin >> n >> m >> q;

  b.assign(n, vector<int>(m, -1));
  s.assign(n, vector<char>(m));
  ans.assign(n, vector<int>(m));

  vector<pair<int, int>> vols;
  for (int i = 0; i < n; i++) {
    string buf;
    cin >> buf;
    for (int j = 0; j < m; j++) {
      s[i][j] = buf[j];
      if (s[i][j] == 'v') {
        vols.emplace_back(i, j);
      }
      if (s[i][j] == '#') {
        px = i;
        py = j;
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
  vector<tuple<int, int, int>> v; // when - x - y;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (is_sea(i, j)) {
        v.emplace_back(b[i][j], i, j);
      }
    }
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  bool first_zero = 1;
  for (auto it : v) {
    int x, y, when;
    tie(when, x, y) = it;
    for (int i = 0; i < 4; i++) {
      int dx = x + x4[i];
      int dy = y + y4[i];
      if (!valid(dx, dy) || !is_sea(dx, dy)) continue;
      if (b[dx][dy] >= when) {
        int modifier = calc({x, y}, {dx, dy});
        for (int c = 0; c < 2; c++) {
          int cur = encode(x, y, c);
          int dcur = encode(dx, dy, c ^ modifier);
          merge(cur, dcur, when);
        }
      }
    }
  }

  while (q--) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    cout << ans[x][y] << '\n';
  }

  return 0;
}
