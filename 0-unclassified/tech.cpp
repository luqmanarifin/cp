#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> g[N], edge[N], temp;
bool done[N], vis[N];
int got[N];

void dfs(int now) {
  if(done[now]) return;
  done[now] = 1;
  temp.emplace_back(now);
  for(int i = 0; i < g[now].size(); i++) {
    dfs(g[now][i]);
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  while(m--) {
    int a, b;
    scanf("%d %d", &a, &b);
    edge[a].emplace_back(b);
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    if(done[i]) continue;
    temp.clear();
    dfs(i);
    
    for(int j = 0; j < temp.size(); j++) {
      int cur = temp[j];
      for(auto it : edge[cur]) {
        got[it]++;
      }
    }
    queue<int> q;
    int edges = 0;
    for(int j = 0; j < temp.size(); j++) {
      int cur = temp[j];
      edges += edge[cur].size();
      if(got[cur] == 0) {
        q.push(cur);
      }
    }
    while(!q.empty()) {
      int now = q.front();
      q.pop();
      if(vis[now]) continue;
      vis[now] = 1;
      for(auto it : edge[now]) {
        got[it]--;
        if(got[it] == 0) {
          q.push(it);
        }
      }
      edges -= edge[now].size();
    }
    if(edges) ans += temp.size();
    else ans += temp.size() - 1;
  }
  cout << ans << endl;
  return 0;
}