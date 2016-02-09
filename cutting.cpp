#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 4;

int par[N], dad[N];
set<int> edge[N];

int source;
void dfs(int now) {
  par[now] = source;
  for(auto it : edge[now]) {
    dfs(it);
  }
}

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
    int n, q;
    scanf("%d %d", &n, &q);
    
    for(int i = 1; i <= n; i++) {
      par[i] = i;
      edge[i].clear();
    }
    
    for(int i = 1; i <= n; i++) {
      scanf("%d", dad + i);
      if(dad[i]) {
        edge[dad[i]].insert(i);
        merge(i, dad[i]);
      }
    }
    printf("Case #%d:\n", tt);
    while(q--) {
      char c;
      scanf(" %c", &c);
      if(c == 'Q') {
        int a, b;
        scanf("%d %d", &a, &b);
        puts(find(a) == find(b)? "YES" : "NO");
      } else {
        int a;
        scanf("%d", &a);
        if(dad[a]) {
          edge[dad[a]].erase(a);
          dad[a] = 0;
        }
        source = a;
        dfs(a);
      }
    }
  }
  
  return 0;
}
