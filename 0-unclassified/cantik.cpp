#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int par[N];
vector<int> edge[N];

int find(int u) {
  return par[u] == u? u : par[u] = find(par[u]);
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    for(int i = 0; i < N; i++) {
      par[i] = i;
      edge[i].clear();
    }
    int n, m;
    scanf("%d %d", &n, &m);
    while(m--) {
      int a, b;
      scanf("%d %d", &a, &b);
      edge[a].push_back(b);
      edge[b].push_back(a);
      merge(a, b);
    }
    bool found = 0;
    for(int i = 1; i <= n && !found; i++) {
      for(int j = i + 1; j <= n && !found; j++) {
        if(find(i) == find(j) && edge[i].size() == 3 && edge[j].size() == 3) {
          puts("cantik");
          found = 1;
        }
      }
    }
    if(!found) puts("tidak cantik");
  }
  
  return 0;
}
