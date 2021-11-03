#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

string dir = "LRDU";
int pos[256];

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

int dp[N][N];
char s[N][N];
int cyc[N][N];
vector<int> edge[N * N];
int n, m;

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

int idx(int i, int j) {
  return i * m + j;
}

void clear() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dp[i][j] = 0;
      cyc[i][j] = -1;
      edge[i * m + j].clear();
    }
  }
}

void bfs(vector<int>& v) {
  queue<int> q;
  for (auto it : v) q.push(it);
  while (!q.empty()) {
    int now = q.front();
    int ncos = dp[now / m][now % m];
    q.pop();
    for (auto it : edge[now]) {
      int i = it / m;
      int j = it % m;
      if (dp[i][j] == 0) {
        q.push(it);
        dp[i][j] = ncos + 1;
      }
    }
  }
}

vector<int> get_cycle(int v) {
  vector<int> num;
  while (1) {
    int i = v / m;
    int j = v % m;
    cyc[i][j] = num.size();
    num.push_back(v);
    int c = pos[s[i][j]];
    int ni = i + dx[c];
    int nj = j + dy[c];
    if (cyc[ni][nj] != -1) {
      vector<int> ret;
      for (int i = cyc[ni][nj]; i < num.size(); i++) {
        ret.push_back(num[i]);
      }
      return ret;
    }
    v = idx(ni, nj);
  }
}

int main() {
  for (int i = 0; i < 4; i++) {
    pos[dir[i]] = i;
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    clear();
    for (int i = 0; i < n; i++) {
      scanf("%s", s[i]);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int c = pos[s[i][j]];
        int ni = i + dx[c];
        int nj = j + dy[c];
        if (valid(ni, nj)) {
          edge[idx(ni, nj)].push_back(idx(i, j));
        } else {
          dp[i][j] = 1;
        }
      }
    }
    // cyclic detection
    vector<int> q;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int now = idx(i, j);
        if (dp[i][j]) {
          q.push_back(now);
        }
      }
    }
    bfs(q);

    // resolve cycle
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (dp[i][j]) continue;
        auto cycle = get_cycle(idx(i, j));
        for (auto it : cycle) {
          int pi = it / m;
          int pj = it % m;
          dp[pi][pj] = cycle.size();
        }
        bfs(cycle);
      }
    }

    int ans = 0, px = 0, py = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (dp[i][j] > ans) {
          ans = dp[i][j];
          px = i;
          py = j;
        }
      }
    }
    printf("%d %d %d\n", px + 1, py + 1, ans);
  }

  return 0;
}
