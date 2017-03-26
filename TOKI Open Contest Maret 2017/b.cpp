#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;
const int POW = 2e5 + 5;

int to[N];
vector<int> edge[N];

vector<long long> all; 
bool vis[N];

void dfs(int now, int done, long long val) {
  if (done == 3) {
    all.push_back(val);
    return;
  }
  for (auto it : edge[now]) {
    if (vis[it / 2] == 0) {
      vis[it / 2] = 1;
      dfs(to[it], done + 1, val * POW + it / 2);
      vis[it / 2] = 0;
    }
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int pt = 0;
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    to[pt] = v;
    edge[u].push_back(pt++);
    
    to[pt] = u;
    edge[v].push_back(pt++);
  }
  assert(pt == 2 * m);
  for (int i = 1; i <= n; i++) dfs(i, 0, 0);
  sort(all.begin(), all.end());
  all.resize(distance(all.begin(), unique(all.begin(), all.end())));
  cout << all.size() << endl;
  return 0;
}
