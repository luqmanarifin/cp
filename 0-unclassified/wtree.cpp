#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

priority_queue<pair<int, int>> pq[2];
int val[N];
int par[N];
int t[N];
int n;

int find(int u) {
  if(par[u] != u) return par[u] = find(par[u]);
  return par[u];
}

void merge(int u, int v) {
  u = find(u);
  v = find(v);
  par[u] = v;
}

void sisa() {
  int root[2];
  root[0] = pq[0].top().second;
  root[1] = pq[1].top().second;
  if(find(root[0]) != find(root[1])) {
    printf("%d %d %d\n", root[0], root[1], 0);
    merge(root[0], root[1]);
  }
  for(int i = 1; i <= n; i++) {
    if(find(i) != find(root[t[i] ^ 1])) {
      printf("%d %d %d\n", i, root[t[i] ^ 1], 0);
      merge(i, root[t[i] ^ 1]);
    }
  }
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d %d", t + i, val + i);
    pq[t[i]].emplace(val[i], i);
    par[i] = i;
  }
  int m = n - 1;
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < 2; j++) {
      while(!pq[j].empty() && val[pq[j].top().second] != pq[j].top().first) {
        pq[j].pop();
      }
    }
    vector<pair<int, int>> save;
    int u = pq[0].top().second;
    while(!pq[1].empty()) {
      if(val[pq[1].top().second] != pq[1].top().first) {
        pq[1].pop();
        continue;
      }
      if(find(u) == find(pq[1].top().second)) {
        save.push_back(pq[1].top());
        pq[1].pop();
        continue;
      }
      int v = pq[1].top().second;
      pq[1].pop();
      int del = min(val[u], val[v]);
      printf("%d %d %d\n", u, v, del);
      val[u] -= del;
      val[v] -= del;
      merge(u, v);
      pq[0].emplace(val[u], u);
      pq[1].emplace(val[v], v);
      if(del == 0) {
        sisa();
        return 0;
      }
      break;
    }
    for(auto it : save) {
      pq[1].push(it);
    }
  }
  
  return 0;
}
