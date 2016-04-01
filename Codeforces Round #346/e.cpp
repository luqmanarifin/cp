#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> edge[N];
bool vis[N];
vector<int> s;

void dfs(int now) {
  if(vis[now]) return;
  vis[now] = 1;
  s.push_back(now);
  for(auto it : edge[now]) {
    dfs(it);
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  while(m--) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    s.clear();
    if(!vis[i]) {
      dfs(i);
      int edges = 0;
      for(auto it : s) {
        edges += edge[it].size();
      }
      edges /= 2;
      if(edges + 1 == s.size()) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
