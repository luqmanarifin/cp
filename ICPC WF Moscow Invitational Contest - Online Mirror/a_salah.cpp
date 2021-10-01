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
  int x = rand() % st.size();
  bool can = dfs(id, 0, st[x]);
  for (auto it : rec) {
    vis[it.first][it.second] = 0;
  }
  if (!can) {
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

void generate(int x, int y) {
  if (udah[x][y]) return;
  udah[x][y] = 1;
  a[max_id].emplace_back(x, y);
  for (int i = 0; i < 3; i++) {
    int fx = x + dx[i];
    int fy = y + dy[i];
    if (!valid(fx, fy)) continue;
    if (s[x][y] != s[fx][fy]) continue;
    generate(fx, fy);
  }
}

vector<int> edge[MAX];
int to[MAX];

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
  printf("tiles: %d\n", max_id);
  for (int i = 0; i < max_id; i++) printf("pos: %d %d, bawah %d %d\n", pos[i].first, pos[i].second, bawah[i].first, bawah[i].second);
  for (int i = 0; i < max_id; i++) {
    printf("id #%d\n", i);
    for (auto it : a[i]) printf("%d %d\n", it.first, it.second);
  }
  cerr << "generate done" << endl;
  for (int i = 0; i < max_id; i++) {
    for (int j = i + 1; j < max_id; j++) {

      printf("comparing %d %d\n", i, j);

      put(i, pos[i], 1);
      bool i_then_j, j_then_i;
      tie(ignore, ignore, i_then_j) = solve(j);
      put(i, pos[i], 0);

      put(j, pos[j], 1);
      tie(ignore, ignore, j_then_i) = solve(i);
      put(j, pos[j], 0);

      printf("i %d & j %d: %d %d\n", i, j, i_then_j, j_then_i);

      if (i_then_j && j_then_i) {

      } else if (i_then_j) {
        edge[i].push_back(j);
        to[j]++;
      } else if (j_then_i) {
        edge[j].push_back(i);
        to[i]++;
      } else {
        puts("-1");
        return 0;
      }
    }
  }
  cerr << "build toposort done" << endl;
  // x, y, id
  priority_queue<tuple<int, int, int>> pq;
  for (int i = 0; i < max_id; i++) if (to[i] == 0) pq.emplace(bawah[i].first, bawah[i].second, i);
  vector<pair<int, string>> ans;
  while (!pq.empty()) {
    int now;
    tie(ignore, ignore, now) = pq.top();
    pq.pop();
    int start; string code; bool solved;
    tie(start, code, solved) = solve(now);
    printf("id %d: %d %d\n", now, pos[now].first, pos[now].second);
    if (!solved) {
      puts("-1");
      return 0;
    }
    put(now, pos[now], 1);
    ans.emplace_back(start, code);
    for (auto it : edge[now]) {
      to[it]--;
      if (to[it] == 0) {
        pq.emplace(bawah[it].first, bawah[it].second, it);
      }
    }
  }
  if (ans.size() != max_id) {
    puts("-1");
    return 0;
  }
  printf("%d\n", ans.size());
  for (auto it : ans) printf("%d %s\n", it.first + 1, it.second.c_str());
  return 0;
}
