#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

int s[N], p[N], r[N];
vector<pair<int, int>> adj[N];
int match[N], matched[N], mark[N];

// The code below finds a augmenting path:
// v is in X, it reaturns true if and only if there is an augmenting path starting from v
bool dfs(int v){
  if(mark[v])
    return false;
  mark[v] = true;
  for(auto &x : adj[v]) {
    auto u = x.second;
    if(match[u] == -1 or dfs(match[u])) // match[i] = the vertex i is matched with in the current matching, initially -1
      return matched[v] = u, match[u] = v, true;
  }
  return false;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", s + i);
  for (int i = 1; i <= m; i++) scanf("%d", p + i);
  for (int i = 1; i <= m; i++) scanf("%d", r + i);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i] <= p[j]) {
        adj[i].emplace_back(r[j], j + n);
      }
    }
    sort(adj[i].begin(), adj[i].end());
  }
  memset(matched, -1, sizeof(matched));
  memset(match, -1, sizeof(match));
  while(true){
    memset(mark, false, sizeof mark);
    bool fnd = false;
    for(int i = 1;i <= n;i ++) if(matched[i] == -1 && !mark[i])
      fnd |= dfs(i);
    if(!fnd)
      break;
  }
  for (int i = 1; i <= n; i++) {
    if (matched[i] == -1) {
      puts("impossible");
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%d%c", matched[i] - n, " \n"[i == n]);
  }
  return 0;
}
