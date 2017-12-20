/**

Heart beats fast
Colours and promises
How to be brave?
How can I love when I'm afraid to fall?
But watching you stand alone,
All of my doubt suddenly goes away somehow.

One step closer

I have died every day waiting for you
Darling, don't be afraid.
I have loved you for a thousand years
I'll love you for a thousand more

Time stands still
Beauty in all she is
I will be brave
I will not let anything take away
What's standing in front of me
Every breath
Every hour has come to this

One step closer
One step closer

I have died every day waiting for you
Darling, don't be afraid.
I have loved you for a thousand years
I'll love you for a thousand more

And all along I believed I would find you
Time has brought your heart to me
I have loved you for a thousand years
I'll love you for a thousand more

*/

#include <bits/stdc++.h>

using namespace std;

const bool SUBMIT = 0;
const string FILENAME = "pushabox";
const int N = 1505;

void open() {
  freopen((FILENAME + ".in").c_str(), "r", stdin);
  freopen((FILENAME + ".out").c_str(), "w", stdout);
}
void close() {
  fclose(stdin);
  fclose(stdout);
}

vector<int> adj[N * N];
int childroot, nblock, counter;
vector<pair<int, int>> block[N * N], bridge, edge;
int num[N * N], low[N * N], artp[N * N], root;

void dfs(int v, int bef = -1) {
  num[v] = low[v] = counter++;
  for (int u : adj[v]) {
    if (num[u] == -1) {
      edge.emplace_back(v, u);
      if (v == root)
        childroot++;
      dfs(u, v);
      if (childroot > 1 && v == root) {
        artp[v] = 1;
        while (edge.size() > 0) {
          auto it = edge.back(); edge.pop_back();
          block[nblock].push_back(it);
          if (it == make_pair(v, u))
            break;
        }
        nblock++;
      }
      if (low[u] >= num[v] && v != root) {
        artp[v] = 1;
        while (edge.size() > 0) {
          auto it = edge.back(); edge.pop_back();
          block[nblock].push_back(it);
          if (it == make_pair(v, u))
            break;
        }
        nblock++;
      }
      if (low[u] > num[v])
        bridge.emplace_back(u, v);
      low[v] = min(low[v], low[u]);
    }
    else if (bef != u && low[v] > num[u]) {
      low[v] = min(low[v], num[u]);
      edge.emplace_back(v, u);
    }
  }
}

char s[N][N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, m, queries;
int dp[N][N][4];
bool bfs[N][N];

int comp[N * N * 4];
int no[N][N][4];

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m && s[i][j] != '#';
}

int id(int i, int j) {
  return i * m + j;
}

int main() {
  if (SUBMIT) open();
  
  scanf("%d %d %d", &n, &m, &queries);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  int ai, aj, bi, bj;
  int ptr = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!valid(i, j)) continue;
      if (s[i][j] == 'A') {
        ai = i;
        aj = j;
      }
      if (s[i][j] == 'B') {
        bi = i;
        bj = j;
      }
      for (int k = 0; k < 4; k++) {
        int ti = i + dx[k];
        int tj = j + dy[k];
        if (!valid(ti, tj)) continue;
        adj[id(i, j)].push_back(id(ti, tj));
        int u = id(i, j);
        int v = id(ti, tj);
        if (u < v) {
          no[i][j][k] = no[ti][tj][k ^ 1] = ptr++;
        }
      }
    }
  }

  memset(low, -1, sizeof low);
  memset(num, -1, sizeof num);
  memset(artp, 0, sizeof artp);
  for (int i = 0; i < n * m; i++) if (num[i] == -1) {
    root = i;
    childroot = 0;
    edge.clear();
    dfs(i);
    artp[i] = childroot > 1;
    if (edge.size() > 0) {
      while (edge.size() > 0) {
        auto it = edge.back(); edge.pop_back();
        block[nblock].push_back(it);
      }
      nblock++;
    }
  }
  
  memset(comp, -1, sizeof(comp));
  for (int i = 0; i < nblock; i++) {
    printf("block %d\n", i);
    for (auto it : block[i]) {
      int u = it.first;
      int v = it.second;
      printf("%d %d\n", u, v);
      for (int k = 0; k < 4; k++) {
        int ti = u / m + dx[k];
        int tj = u % m + dy[k];
        if (!valid(ti, tj)) continue;
        if (v == id(ti, tj)) {
          int id = no[u / m][u % m][k];
          comp[id] = i;
          break;
        }
      }
    }
  }
    
  queue<pair<int, int>> d;
  bfs[ai][aj] = 1;
  d.emplace(ai, aj);
  while (!d.empty()) {
    int ni, nj;
    tie(ni, nj) = d.front();
    d.pop();
    for (int k = 0; k < 4; k++) {
      int ti = ni + dx[k];
      int tj = nj + dy[k];
      if (!valid(ti, tj)) continue;
      if (s[ti][tj] == 'B') continue;
      if (bfs[ti][tj]) continue;
      bfs[ti][tj] = 1;
      d.emplace(ti, tj);
    }
  }
  queue<tuple<int, int, int>> q;
  for (int k = 0; k < 4; k++) {
    int ti = bi + dx[k];
    int tj = bj + dy[k];
    if (!valid(ti, tj)) continue;
    if (bfs[ti][tj]) {
      q.emplace(bi, bj, k);
      dp[bi][bj][k] = 1;
    }
  }
  while (!q.empty()) {
    int ni, nj, nk;
    tie(ni, nj, nk) = q.front();
    q.pop();
    int ti = ni + dx[nk ^ 1];
    int tj = nj + dy[nk ^ 1];
    if (valid(ti, tj) && !dp[ti][tj][nk]) {
      dp[ti][tj][nk] = 1;
      q.emplace(ti, tj, nk);
    }
    int oi = ni + dx[nk];
    int oj = nj + dy[nk];
    for (int k = 0; k < 4; k++) {
      ti = ni + dx[k];
      tj = nj + dy[k];
      if (!valid(ti, tj)) continue;
      if (comp[no[ni][nj][nk]] == comp[no[ni][nj][k]] && comp[no[ni][nj][nk]] != -1 && !dp[ni][nj][k]) {
        dp[ni][nj][k] = 1;
        q.emplace(ni, nj, k);
      }
    }
  }
  while (queries--) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    if (u == bi && v == bj) {
      puts("YES");
      continue;
    }
    bool ok = 0;
    for (int k = 0; k < 4; k++) ok |= dp[u][v][k];
    puts(ok? "YES" : "NO");
  }
  
  if (SUBMIT) close();
  
  return 0;
}
