#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> edge[N];
bool leaf[N];

vector<int> adj[N];

void dfs(int now) {
  if (leaf[now]) return;
  if (edge[now].size() > 2) return;
  leaf[now] = 1;
  for (auto it : edge[now]) dfs(it);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (edge[i].size() <= 1) {
      dfs(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (leaf[i]) continue;
    for (auto it : edge[i]) {
      if (leaf[it]) continue;
      adj[i].push_back(it);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (adj[i].size() > 2) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  return 0;
}
