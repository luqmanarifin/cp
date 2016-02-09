#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

vector<pair<int, int>> all[N], edge[N];
bool vis[N];

int main() {
  int n, m, s, t;
  scanf("%d %d %d %d", &n, &m, &s, &t);
  while(m--) {
    int u, v, c;
    scanf("%d %d %d", &u, &v, &c);
    all[u].emplace_back(v, c);
    all[v].emplace_back(u, c);
  }
  int ans = 0;
  for(int b = 30; b >= 0; b--) {
    for(int i = 1; i <= n; i++) {
      vis[i] = 0;
      edge[i].clear();
      for(auto it : all[i]) {
        if((it.second & (1 << b)) == 0) {
          edge[i].push_back(it);
        }
      }
    }
    vis[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
      int now = q.front();
      q.pop();
      if(now == t) break;
      for(auto it : edge[now]) {
        int near = it.first;
        if(!vis[near]) {
          vis[near] = 1;
          q.push(near);
        }
      }
    }
    if(vis[t]) {
      for(int i = 1; i <= n; i++) {
        all[i] = edge[i];
      }
    } else {
      ans ^= (1 << b);
    }
  }
  cout << ans << endl;
  return 0;
}
