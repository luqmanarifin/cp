#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int par[N];

int find(int u) {
  return (par[u] == u? u : par[u] = find(par[u]));
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
    }
    vector<tuple<int, int, int>> p;
    
    int n, m;
    scanf("%d %d", &n, &m);
    while(m--) {
      int u, v, c;
      scanf("%d %d %d", &u, &v, &c);
      p.emplace_back(c, u, v);
    }
    sort(p.begin(), p.end());
    int rem = n - 1;
    for(int i = 0; i < p.size() && rem; i++) {
      int c, u, v;
      tie(c, u, v) = p[i];
      if(find(u) != find(v)) {
        merge(u, v);
        rem--;
      }
      if(rem == 0) {
        printf("%d\n", c);
        break;
      }
    }
  }
  
  return 0;
}
