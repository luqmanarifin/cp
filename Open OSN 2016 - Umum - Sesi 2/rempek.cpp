#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
const int M = 3e5 + 5;
const int inf = 2e9;
const int mod = 1e9 + 7;

char junk[55], s[N][N];
int n, m, K, q;
int dist[N][N], par[M], siklik[M];
vector<int> rev[M];
vector<pair<int, int>> pos;
int at[N][N];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool valid(int i, int j) {
  return 1 <= i && i <= n && 1 <= j && j <= m;
}

void isi(int now, int val) {
  par[now] = val;
  for (auto it : rev[now]) isi(it, val);
}

pair<int, int> join(pair<int, int> l, pair<int, int> r) {
  if (l.first < r.first) return l;
  if (l.first > r.first) return r;
  if (l.second != r.second) return {l.first, -1};
  return l;
}

pair<int, int> add(pair<int, int> l) {
  return {l.first + 1, l.second};
}

pair<int, int> a[N][N], here[N][N];

void reset() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      a[i][j] = {1e9, -1};
    }
  }
}

int main() {
  scanf("%s %d %d %d %d", junk, &n, &m, &K, &q);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  queue<pair<int, int>> que;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dist[i][j] = inf;
      if (s[i][j] == 'X') {
        dist[i][j] = 0;
        at[i][j] = pos.size();
        que.emplace(i, j);
        pos.emplace_back(i, j);
      }
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      a[i][j] = here[i][j] = {1e9, -1};
    }
  }
  while (!que.empty()) {
    int i, j;
    tie(i, j) = que.front();
    que.pop();
    for (int k = 0; k < 4; k++) {
      int ti = i + dx[k];
      int tj = j + dy[k];
      if (!valid(ti, tj)) continue;
      if (dist[i][j] + 1 < dist[ti][tj]) {
        dist[ti][tj] = dist[i][j] + 1;
        que.emplace(ti, tj);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      a[i][j] = join(a[i][j], add(a[i][j-1]));
      a[i][j] = join(a[i][j], add(a[i-1][j]));
      if (s[i][j] == 'X') {
        a[i+1][j] = join(a[i+1][j], {1, at[i][j]});
        a[i][j+1] = join(a[i][j+1], {1, at[i][j]});
      }
      here[i][j] = join(here[i][j], a[i][j]);
    }
  }
  reset();
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= 1; j--) {
      a[i][j] = join(a[i][j], add(a[i][j+1]));
      a[i][j] = join(a[i][j], add(a[i-1][j]));
      if (s[i][j] == 'X') {
        a[i+1][j] = join(a[i+1][j], {1, at[i][j]});
        a[i][j-1] = join(a[i][j-1], {1, at[i][j]});
      }
      here[i][j] = join(here[i][j], a[i][j]);
    }
  }
  reset();
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= m; j++) {
      a[i][j] = join(a[i][j], add(a[i][j-1]));
      a[i][j] = join(a[i][j], add(a[i+1][j]));
      if (s[i][j] == 'X') {
        a[i-1][j] = join(a[i-1][j], {1, at[i][j]});
        a[i][j+1] = join(a[i][j+1], {1, at[i][j]});
      }
      here[i][j] = join(here[i][j], a[i][j]);
    }
  }
  reset();
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      a[i][j] = join(a[i][j], add(a[i][j+1]));
      a[i][j] = join(a[i][j], add(a[i+1][j]));
      if (s[i][j] == 'X') {
        //printf("nyebar %d %d\n", i, j);
        a[i-1][j] = join(a[i-1][j], {1, at[i][j]});
        a[i][j-1] = join(a[i][j-1], {1, at[i][j]});
      }
      here[i][j] = join(here[i][j], a[i][j]);
    }
  }
  /*
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      printf("%d ", here[i][j].second);
    }
    printf("\n");
  }
  */
  for (int i = 0; i < pos.size(); i++) {
    par[i] = here[pos[i].first][pos[i].second].second;
    if (par[i] == -1) par[i] = i;
  }
  for (int i = 0; i < pos.size(); i++) {
    //printf("par %d-%d: %d-%d\n", pos[i].first, pos[i].second, pos[par[i]].first, pos[par[i]].second);
    if (par[par[i]] == i) {
      siklik[i] = 1;
    }
    rev[par[i]].push_back(i);
  }
  for (int i = 0; i < pos.size(); i++) {
    if (siklik[i]) {
      for (auto it : rev[i]) {
        if (siklik[it]) continue;
        isi(it, par[i]);
      }
    }
  }
  while (q--) {
    int u, v;
    scanf("%d %d", &u, &v);
    int node;
    if (here[u][v].second == -1) {
      printf("%d %d\n", u, v);
      continue;
    }
    if (s[u][v] == 'X' && siklik[at[u][v]]) {
      node = here[u][v].second;
    } else {
      node = here[u][v].second;
      node = par[node];
    }
    printf("%d %d\n", pos[node].first, pos[node].second);
  }
  return 0;
}
