#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> edge[N];
int h[N], kid[N];
double p[N];

void dfs(int now, int bef) {
  for (auto it : edge[now]) {
    if (bef == it) continue;
    h[it] = h[now] + 1;
    dfs(it, now);
    kid[now]++;
  }
}

void penis(int now, int bef) {
  for (auto it : edge[now]) {
    if (bef == it) continue;
    p[it] = p[now] / kid[now];
    penis(it, now);
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
  dfs(1, 0);
  p[1] = 1;
  penis(1, 0);
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    if (kid[i] == 0) {
      ans += p[i] * h[i];
    }
  }
  printf("%.15f\n", ans);
  return 0;
}
