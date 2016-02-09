#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int par[N], done[N];

int find(int u) {
  return par[u] == u? u : par[u] = find(par[u]);
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

int p[N];

int main() {
  for(int i = 0; i < N; i++) {
    par[i] = i;
  }
  
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", p + i);
  }
  vector<pair<int, int>> edges; 
  for(int i = 1; i <= n; i++) {
    if(i != p[p[i]]) {
      puts("NO");
      return 0;
    }
    merge(i, p[i]);
    if(i != p[i] && !done[i] && !done[p[i]]) {
      edges.emplace_back(i, p[i]);
    }
    done[i] = 1; done[p[i]] = 1;
  }
  puts("YES");
  for(int i = 1; i <= n; i++) {
    if(find(i) != find(1)) {
      printf("%d %d\n", i, 1);
      merge(1, i);
    }
  }
  for(auto it : edges) {
    printf("%d %d\n", it.first, it.second);
  }
  return 0;
}
