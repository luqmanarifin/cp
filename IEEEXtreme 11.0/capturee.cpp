#include <bits/stdc++.h>

using namespace std;

// functions used to comunicate with the interactor (the other program)
// use this to get the position of the other player.
// after using it you must do your own move
// TL;DR GetBlack() GetBlack() is invalid
int GetBlack() {
  int black_king_node;
  cin >> black_king_node;
  return black_king_node;
}
// use this to set your own move
void SetWhite(int node) {
  cout << node << endl;
  fflush(stdout);
}

const int N = 105;
const int inf = 1e9;

vector<int> edge[N];
int n, m, dp[N][N][2], vis[N][N][2], d[N][N];
int got[N][N][2];

void ReadGraph() {
  cin >> n >> m;
  for (int i = 0; i < m; i += 1) {
    int a, b;
    cin >> a >> b;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
}

int dfs(int s, int t, int c) {
  if (dp[s][t][c] != -1) return dp[s][t][c];
  if (vis[s][t][c]) {
    if (c == 0) {
      return -inf;
    } else {
      return inf;
    }
  }
  vis[s][t][c] = 1;
  if (c == 0) {
    dp[s][t][c] = inf;
    for (auto it : edge[s]) {
      if (d[it][t] < d[s][t]) {
        int cur = dfs(it, t, c ^ 1) + 1;
        if (dp[s][t][c] > cur) {
          dp[s][t][c] = cur;
          got[s][t][c] = it;
        }
      }
    }
  } else {
    dp[s][t][c] = dfs(s, t, c ^ 1) + 1;
    for (auto it : edge[t]) {
      if (d[it][t] >= d[s][t]) {
        int cur = dfs(s, it, c ^ 1) + 1;
        if (dp[s][t][c] < cur) {
          dp[s][t][c] = cur;
          got[s][t][c] = it;
        }
      }
    }
  }
  vis[s][t][c] = 0;
  return dp[s][t][c];
}

int main() {
  ReadGraph();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) d[i][j] = inf;
    d[i][i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    for (auto it : edge[i]) d[i][it] = d[it][i] = 1;
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  int s = 0, t = 0;
  int mini = inf;
  for (int i = 1; i <= n; i++) {
    int maxi = -1;
    for (int j = 1; j <= n; j++) {
      //printf("%d %d %d\n", i, j, d[i][j]);
      if (d[i][j] > maxi) {
        maxi = d[i][j];
      }
    }
    //printf("%d terjauh %d\n", i, maxi);
    if (maxi < mini) {
      s = i;
      mini = maxi;
    }
  }
  SetWhite(s);
  t = GetBlack();
  while (s != t) {
    memset(dp, -1, sizeof(dp));
    dfs(s, t, 0);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        
      }
    }
    
    SetWhite(got[s][t][0]);
    s = got[s][t][0];
    if (s == t) break;
    t = GetBlack();
  }
  return 0;
}
