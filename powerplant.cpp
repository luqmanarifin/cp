#include <bits/stdc++.h>

using namespace std;

const int N = 205;

int par[N];
int a[N];

int find(int u) {
  return u == par[u]? u : par[u] = find(par[u]);
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    for(int i = 0; i < N; i++) {
      par[i] = i;
    }
    
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= k; i++) {
      scanf("%d", a + i);
    }
    for(int i = 2; i <= k; i++) {
      merge(a[i - 1], a[i]);
    }
    vector<tuple<int, int, int>> edges;
    while(m--) {
      int u, v, c;
      scanf("%d %d %d", &u, &v, &c);
      edges.emplace_back(c, u, v);
    }
    sort(edges.begin(), edges.end());
    int ans = 0;
    for(auto it : edges) {
      int c, u, v;
      tie(c, u, v) = it;
      if(find(u) != find(v)) {
        ans += c;
      }
      merge(u, v);
    }
    printf("Case #%d: %d\n", tt, ans);
  }
  
  return 0;
}
