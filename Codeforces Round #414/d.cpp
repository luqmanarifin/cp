#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

set<pair<int, int>> edges;
vector<int> edge[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edges.insert(make_pair(u, v));
    edges.insert(make_pair(v, u));
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  int best = 1e9, p = -1
  for (int i = 0; i < n; i++) 

  return 0;
}
