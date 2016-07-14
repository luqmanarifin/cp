#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int par[N], a[N];
vector<tuple<int, int, int>> edges;
char s[N];

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
    edges.clear();
    for(int i = 0; i < N; i++) par[i] = i;
    
    int n;
    scanf("%d %s", &n, s + 1);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    for(int i = 1; i < n; i++) {
      edges.emplace_back(a[i + 1] - a[i], i, i + 1);
    }
    sort(edges.begin(), edges.end());
    for(int i = 1; i <= n; i++) {
      if(s[i] == '1') {
        merge(i, 0);
      }
    }
    long long ans = 0;
    for(auto it : edges) {
      int c, u, v;
      tie(c, u, v) = it;
      if(find(u) != find(v)) {
        merge(u, v);
        ans += c;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
