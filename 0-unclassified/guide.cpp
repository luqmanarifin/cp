#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

vector<int> edge[N], node[N];
int par[N], vis[N], good[N];
vector<vector<int>> ans;

int dfs(int now) {
  vis[now] = 1;
  for(auto it : edge[now]) {
    if(vis[it]) continue;
    par[it] = now;
    int g = dfs(it);
    if(g != -1) {
      node[now].push_back(g);
    }
  }
  if(node[now].size() % 2 == 1) {
    if(good[now]) {
      node[now].push_back(now);
      return -1;
    } else {
      int leaf = node[now].back();
      node[now].pop_back();
      return leaf;
    }
  } else {
    return good[now]? now : -1;
  }
}

vector<int> route(int from, int to) {
  vector<int> ret;
  int now = from;
  while(now != to) {
    ret.push_back(now);
    now = par[now];
  }
  return ret;
}

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  while(m--) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  while(k--) {
    int u;
    scanf("%d", &u);
    good[u] = 1;
  }
  for(int i = 1; i <= n; i++) {
    if(!vis[i]) {
      dfs(i);
    }
  }
  for(int i = 1; i <= n; i++) {
    assert(node[i].size() % 2 == 0);
    for(int j = 0; j < node[i].size(); j += 2) {
      vector<int> a = route(node[i][j], i);
      vector<int> b = route(node[i][j + 1], i);
      reverse(b.begin(), b.end());
      vector<int> path;
      for(auto it : a) {
        path.push_back(it);
      }
      path.push_back(i);
      for(auto it : b) {
        path.push_back(it);
      }
      ans.push_back(path);
    }
  }
  printf("%d\n", ans.size());
  for(auto v : ans) {
    printf("%d ", v.size() - 1);
    for(auto it : v) {
      printf("%d ", it);
    }
    printf("\n");
  }
  return 0;
}
