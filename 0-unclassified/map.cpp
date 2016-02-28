#include <bits/stdc++.h>

using namespace std;

int par[1005];
vector<tuple<int, int, int>> edges;

int find(int u) {
  return par[u] == u? u : par[u] = find(par[u]);
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}


int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  while(m--) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    edges.emplace_back(c, a, b);
  }
  for(int i = 1; i <= n; i++) {
    par[i] = i;
  }
  sort(edges.begin(), edges.end());
  long long ans = 0;
  int nice = 0;
  for(auto it : edges) {
    int c, a, b;
    tie(c, a, b) = it;
    if(find(a) == find(b)) {
      ans += c;
    } else {
      merge(a, b);
      nice++;
    }
  }
  cout << (nice == n - 1? ans : -1) << endl;;
  return 0;
}
