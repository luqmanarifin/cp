#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int inf = 1e9;

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

int n, m;
vector<int> edge[N];
int dp[N][N][2];  // 0 giliran gua
bool vis[N][N][2];
int got[N][N][2];
int d[N][N];


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
  //printf("%d %d %d: %d\n", s, t, c, dp[s][t][c]);
  if (dp[s][t][c] != -1) {
    if (vis[s][t][c]) {
      if (c == 0) {
        return -inf;
      } else {
        return inf;
      }
    } else {
      return dp[s][t][c];
    }
  }
  if (s == t && s) {
    dp[s][t][c] = 0;
    return dp[s][t][c];
  }
  vis[s][t][c] = 1;
  if (c == 0) {
    dp[s][t][c] = inf;
    // kita jalan
    for (auto it : edge[s]) {
      if (d[it][t] >= d[s][t]) continue;
      if (dp[s][t][c] > dfs(it, t, 1) + 1) {
        dp[s][t][c] = dfs(it, t, 1) + 1;
        got[s][t][c] = it;
      }
    }
  } else {
    dp[s][t][c] = -inf;
    // musuh diem
    if (t != 0) {
      dp[s][t][c] = dfs(s, t, c ^ 1) + 1;
      got[s][t][c] = t;
    }
    // musuh jalan
    for (auto it : edge[t]) {
      if (d[s][it] < d[s][t]) continue;
      if (dp[s][t][c] < dfs(s, it, c ^ 1) + 1) {
        dp[s][t][c] = dfs(s, it, c ^ 1) + 1;
        got[s][t][c] = it;
      }
    }
  }
  vis[s][t][c] = 0;
  //printf("dapet %d %d %d: %d\n", s, t, c, dp[s][t][c]);
  return dp[s][t][c];
}

int main() {
  // use this to pass the first example
  ReadGraph();
  for (int i = 1; i <= n; i++) {
    edge[0].push_back(i);
  }
  for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) d[i][j] = inf;
  
  for (int i = 0; i < N; i++) d[i][i] = 0, d[0][i] = d[i][0] = 1;
  for (int i = 1; i <= n; i++) for (auto it : edge[i]) d[i][it] = d[it][i] = 1;
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (d[i][j] > d[i][k] + d[k][j]) {
          d[i][j] = d[i][k] + d[k][j];
        }
      }
    }
  }
  
  int s = 0, t = 0;
  while (!(s == t && s != 0)) {
    memset(dp, -1, sizeof(dp));
    dfs(s, t, 0);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        printf("%d %d %d: %d ke %d\n", i, j, 0, dp[i][j][0], got[i][j][0]);
        printf("%d %d %d: %d ke %d\n", i, j, 1, dp[i][j][1], got[i][j][1]);
      }
    }
    
    SetWhite(got[s][t][0]);
    s = got[s][t][0];
    if (s == t) break;
    t = GetBlack();
  }
  
  return 0;
}

