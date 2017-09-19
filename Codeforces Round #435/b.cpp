#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> edge[N];
int c[N];

void dfs(int now, int bef, int col) {
  c[now] = col;
  for (auto it : edge[now]) {
    if (it == bef) continue;
    dfs(it, now, col ^ 1);
  }
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
  dfs(1, 0, 0);
  long long ans = 0;
  int item = 0;
  for (int i = 1; i <= n; i++) if (c[i]) item++;
  for (int i = 1; i <= n; i++) if (!c[i]) {
    int ada_item = 0;
    for (auto it : edge[i]) {
      if (c[it]) {
        ada_item++;
      }
    }
    ans += item - ada_item;
  }
  cout << ans << endl;
  return 0;
}
