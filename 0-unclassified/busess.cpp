// kadalbonek
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> edge[N];
tuple<int, int, int> edges[N];
int par[N];
vector<int> comp[N];

int find(int u) {
  return par[u] == u? u : par[u] = find(par[u]);
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

int dfs(int now, int prev) {
  int bus = now;
  for(auto it : edge[now]) {
    if(it == prev) {
      continue;
    }
    int other = dfs(it, now);
    printf("Drive %d %d %d\n", other, it, now);
    if(comp[bus].size() < comp[other].size()) {
      for(auto c : comp[bus]) {
        printf("Move %d %d %d\n", c, bus, other);
        comp[other].push_back(c);
      }
      bus = other;
    } else {
      for(auto c : comp[other]) {
        printf("Move %d %d %d\n", c, other, bus);
        comp[bus].push_back(c);
      }
    }
  }
  return bus;
}

int main() {
  for(int i = 0; i < N; i++) {
    par[i] = i;
    comp[i].push_back(i);
  }
  
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    edges[i] = make_tuple(c, a, b);
  }
  sort(edges, edges + m);
  long long ans = 0;
  for(int i = 0; i < m; i++) {
    int c, a, b;
    tie(c, a, b) = edges[i];
    if(find(a) != find(b)) {
      ans += c;
      edge[a].push_back(b);
      edge[b].push_back(a);
      merge(a, b);
    }
  }
  printf("%I64d\n", ans);
  dfs(1, -1);
  puts("Done");
  return 0;
}
