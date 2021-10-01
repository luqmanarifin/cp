#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int MAX = 2505;

char s[N][N];
vector<pair<int, int>> a[MAX];
pair<int, int> pos[MAX], bawah[MAX];
int n, m, max_id;

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

// current map
bool done[N][N];

void put(int id, pair<int, int> at, int val) {
  for (auto it : a[id]) {
    done[at.first + it.first][at.second + it.second] = val;
  }
}

bool can(int id, pair<int, int> at) {
  for (auto it : a[id]) {
    int px = at.first + it.first;
    int py = at.second + it.second;
    if (!valid(px, py)) return 0;
    if (done[px][py]) return 0;
  }
  return 1;
}

vector<pair<int, int>> rec;
bool vis[N][N];
int backtrack[N][N];
int dx[] = {1, 0, 0}, dy[] = {0, -1, 1};
string ARAH = "DLR";

bool dfs(int id, int x, int y) {
  int gx = pos[id].first;
  int gy = pos[id].second;
  if (gx == x && gy == y) return 1;
  vis[x][y] = 1;
  rec.emplace_back(x, y);
  for (int i = 0; i < 3; i++) {
    int fx = x + dx[i];
    int fy = y + dy[i];
    if (fx > gx) continue;
    if (!can(id, {fx, fy})) continue;
    if (vis[fx][fy]) continue;
    backtrack[fx][fy] = i;
    if (dfs(id, fx, fy)) return 1;
  }
  return 0;
}

tuple<int, string, bool> solve(int id) {
  vector<int> st;
  for (int j = 0; j < m; j++) {
    if (can(id, {0, j})) st.push_back(j);
  }
  if (st.empty()) return {0, "", false};
  random_shuffle(st.begin(), st.end());
  bool found = 0;
  rec.clear();
  for (auto it : st) {
    bool can = dfs(id, 0, it);
    if (can) {
      found = 1;
      break;
    }
  }
  for (auto it : rec) {
    vis[it.first][it.second] = 0;
  }
  if (!found) {
    return {0, "", false};
  }
  int px = pos[id].first, py = pos[id].second;
  vector<char> ans;
  while (px != 0) {
    int c = backtrack[px][py];
    ans.push_back(ARAH[c]);
    px -= dx[c];
    py -= dy[c];
  }
  reverse(ans.begin(), ans.end());
  string ret = "";
  for (auto it : ans) ret += it;
  ret += "S";
  return {py, ret, true};
}

bool udah[N][N];
int rx[] = {1, -1, 0, 0};
int ry[] = {0, 0, 1, -1};

void generate(int x, int y) {
  if (udah[x][y]) return;
  udah[x][y] = 1;
  a[max_id].emplace_back(x, y);
  for (int i = 0; i < 4; i++) {
    int fx = x + rx[i];
    int fy = y + ry[i];
    if (!valid(fx, fy)) continue;
    if (s[x][y] != s[fx][fy]) continue;
    generate(fx, fy);
  }
}

vector<int> edge[MAX];
int to[MAX];
bool removed[MAX];

int main() {
  srand(time(NULL));
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] != '.' && !udah[i][j]) {
        generate(i, j);
        pos[max_id] = {i, j};
        bawah[max_id] = {-i, j};
        for (auto it : a[max_id]) {
          pos[max_id] = min(pos[max_id], it);
          bawah[max_id] = min(bawah[max_id], {-it.first, it.second});
        }
        bawah[max_id].first = -bawah[max_id].first;
        for (auto& it : a[max_id]) {
          it.first -= pos[max_id].first;
          it.second -= pos[max_id].second;
        }
        max_id++;
      }
    }
  }
  for (int i = 0; i < max_id; i++) {
    put(i, pos[i], 1);
  }
  vector<pair<int, string>> ans;
  while (ans.size() < max_id) {
    bool found = 0;
    for (int i = 0; i < max_id; i++) {
      if (removed[i]) continue;
      put(i, pos[i], 0);
      int start; string code; bool solved;
      tie(start, code, solved) = solve(i);
      if (solved) {
        found = 1;
        removed[i] = 1;
        ans.emplace_back(start, code);
        break;
      }
      put(i, pos[i], 1);
    }
    if (!found) {
      puts("-1");
      return 0;
    }
  }
  reverse(ans.begin(), ans.end());
  printf("%d\n", ans.size());
  for (auto it : ans) printf("%d %s\n", it.first + 1, it.second.c_str());
  return 0;
}
