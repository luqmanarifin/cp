#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> edge[N];
int a[N];

int dfs(int now, int v) {
  if (a[now] != -1) {
    if (a[now] != v) {
      return -1;
    } else {
      return 0;
    }
  }
  a[now] = v;
  for (auto it : edge[now]) {
    if (dfs(it, v ^ 1) == -1) {
      return -1;
    }
  }
  return 0;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  memset(a, -1, sizeof(a));
  for (int i = 1; i <= n; i++) {
    if (a[i] == -1) {
      if (dfs(i, 0) == -1) {
        puts("-1");
        return 0;
      }
    }
  }
  int k = 0;
  for (int i = 1; i <= n; i++) if (a[i] == 0) k++;
  printf("%d\n", k);
  for (int i = 1; i <= n; i++) if (a[i] == 0) printf("%d ", i); printf("\n");
  printf("%d\n", n - k);
  for (int i = 1; i <= n; i++) if (a[i] == 1) printf("%d ", i); printf("\n");
  return 0;
}
