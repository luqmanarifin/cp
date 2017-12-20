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

const bool SUBMIT = 1;
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

/****** Tarjan’s SCC *******/
vector< int > num, low, S, vis;
int cntr, numCC;
vector<int> adj[N * N];
int comp[N * N];

void tarjanSCC(int v, int bef) {
  low[v] = num[v] = ++cntr;
  vis[v] = 1;
  S.push_back(v);
  for(auto u : adj[v]) {
    if (u == bef) continue;
    if(num[u] == -1)
      tarjanSCC(u, v);
    if(vis[u])
      low[v] = min(low[v], low[u]);
  }
  if(low[v] == num[v]) {
    vector<int> el;
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      el.push_back(u);
      if(u == v)
        break;
    }
    if (el.size() > 1) for (auto it : el) comp[it] = numCC;
    numCC++;
  }
}

char s[N][N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, m, queries;
int dp[N][N][4];
bool bfs[N][N];

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m && s[i][j] != '#';
}

int id(int i, int j) {
  return i * m + j;
}

bool reachable(int a, int b, int c, int d) {
  int u = id(a, b);
  int v = id(c, d);
  return comp[u] != -1 && comp[u] == comp[v];
}

int main() {
  if (SUBMIT) open();
  
  scanf("%d %d %d", &n, &m, &queries);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  int ai, aj, bi, bj;
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
      }
    }
  }

  num.assign(n * m, -1);
  low.assign(n * m, 0);
  vis.assign(n * m, 0);
  cntr = numCC = 0;
  memset(comp, -1, sizeof(comp));
  for(int i = 0; i < n * m; i++)
    if(num[i] == -1)
      tarjanSCC(i, -1);
    
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
      if (reachable(oi, oj, ti, tj) && !dp[ni][nj][k]) {
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