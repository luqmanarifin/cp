#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

/****** Tarjan’s SCC *******/
vector< int > num, low, S, vis;
int cntr, numCC;
vector<int> adj[N];
vector<int> el[N];

void tarjanSCC(int v) {
  low[v] = num[v] = ++cntr;
  vis[v] = 1;
  S.push_back(v);
  for(auto u : adj[v]) {
    if(num[u] == -1)
      tarjanSCC(u);
    if(vis[u])
      low[v] = min(low[v], low[u]);
  }
  if(low[v] == num[v]) {
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      el[numCC].push_back(u);
      if(u == v)
        break;
    }
    ++numCC;
  }
}

char s[N];
int dp[N][26];

int main() {
  int n, m;
  scanf("%d %d %s", &n, &m, s + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    if (u == v) {
      puts("-1");
      return 0;
    }
  }
  num.assign(N, -1);
  low.assign(N, 0);
  vis.assign(N, 0);
  cntr = numCC = 0;
  for(int i = 1; i<=n; i++)
    if(num[i] == -1)
      tarjanSCC(i);
  
  for (int i = 0; i < numCC; i++) {
    if (el[i].size() > 1) {
      puts("-1");
      return 0;
    }
  }
  vector<int> to(N);
  for (int i = 1; i <= n; i++) {
    for (auto it : adj[i]) to[it]++;
  }
  queue<int> q;
  for (int i = 1; i <= n; i++) if (to[i] == 0) q.push(i);
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    dp[now][s[now] - 'a']++;
    for (auto it : adj[now]) {
      for (int i = 0; i < 26; i++) dp[it][i] = max(dp[it][i], dp[now][i]);
      to[it]--;
      if (to[it] == 0) {
        q.push(it);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 26; j++) {
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << endl;
  return 0;
}
