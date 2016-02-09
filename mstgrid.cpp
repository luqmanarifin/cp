#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int cor = 1005;
const int inf = 1e9;

int x[N], y[N];
vector<tuple<int, int, int>> p;
vector<int> edge[N];
int pos[cor][cor];
int par[N];
int last[cor];

int find(int u) {
  return par[u] == u? u : par[u] = find(par[u]);
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

int main() {
  memset(pos, -1, sizeof(pos));
  for(int i = 0; i < N; i++) {
    par[i] = i;
  }
  
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", x + i, y + i);
    if(pos[x[i]][y[i]] == -1) {
      p.emplace_back(x[i], y[i], i);
      pos[x[i]][y[i]] = i;
    } else {
      merge(i, pos[x[i]][y[i]]);
    }
  }
  sort(p.begin(), p.end());
  
  memset(last, -1, sizeof(last));
  for(int i = 0; i < p.size(); i++) {
    int px, py, id;
    tie(px, py, id) = p[i];
    
    vector<pair<int, int>> pmin;
    for(int t = 0; t < cor; t++) {
      if(last[t] != -1) {
        int ncos = abs(py - t) + abs(px - x[last[t]]);
        pmin.emplace_back(ncos, last[t]);
      }
    }
    sort(pmin.begin(), pmin.end());
    for(int j = 0; j < pmin.size() && j < 10; j++) {
      edge[id].push_back(pmin[j].second);
    }
    last[py] = id;
  }
  
  // cost, from, to
  vector<tuple<int, int, int>> edges;
  for(int i = 0; i < n; i++) {
    for(auto it : edge[i]) {
      edges.emplace_back(abs(x[i] - x[it]) + abs(y[i] - y[it]), i, it);
    }
  }
  sort(edges.begin(), edges.end());
  
  long long ans = 0;
  for(auto it : edges) {
    int w, a, b;
    tie(w, a, b) = it;
    if(find(a) != find(b)) {
      ans += w;
      merge(a, b);
    }
  }
  cout << ans << endl;
  return 0;
}
