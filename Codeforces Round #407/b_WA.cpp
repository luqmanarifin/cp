#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

vector<int> edge[N];
int n, m;
bool vis[N];

void dfs(int now) {
  if (vis[now]) return;
  vis[now] = 1;
  for (auto it : edge[now]) dfs(it);
}

bool connected() {
  //puts("lala");
  for (int i = 1; i <= n; i++) {
    if (edge[i].size()) {
      dfs(i);
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    //printf("%d %d\n", i, vis[i]);
    if (edge[i].size() && !vis[i]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    if (u != v) edge[v].push_back(u);
  }
  //puts("wtf");
  if (m < 2 || !connected()) {
    puts("0");
    return 0;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) ans += 1LL * edge[i].size() * (edge[i].size() - 1) / 2;
  cout << ans << endl;
  return 0;
}
