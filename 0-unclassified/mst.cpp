#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

// par[x] = siapa parent dari node x
int par[N];

// harus dipanggil pertama kali
void init() {
  for (int i = 0; i < N; i++) par[i] = i;
}

// mengembalikan parent dari node u
int find(int u) {
  if (par[u] == u) {
    return u;
  } else {
    return par[u] = find(par[u]);
  }
}

// gabung group milik node u dan v
void merge(int u, int v) {
  par[find(u)] = find(v);
}

int main() {
  init();
  int n, m;
  scanf("%d %d", &n, &m);
  vector<tuple<int, int, int>> edges;   // cost - u - v
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    edges.emplace_back(w, u, v);
  }
  
  // sort edges by cost (ascending)
  sort(edges.begin(), edges.end());
  
  long long mst_cost = 0;
  for (auto it : edges) {
    int w, u, v;
    tie(w, u, v) = it;
    
    // kalau dia tidak berada dalam satu grup
    if (find(u) != find(v)) {
      merge(u, v);
      mst_cost += w;
    }
  }
  cout << mst_cost << endl;
  return 0;
}