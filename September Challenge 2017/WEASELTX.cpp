#include <bits/stdc++.h>

using namespace std;

const int N = 2e5;
const int PERIOD = (1 << 18);

vector<int> edge[N + 5];
long long a[N + 5], h[N + 5];
long long ans[PERIOD];

void dfs(int now, int bef, int d) {
  h[d] ^= a[now];
  for (auto it : edge[now]) {
    if (it == bef) continue;
    dfs(it, now, d + 1);
  }
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  for (int i = 0; i < n; i++) scanf("%lld", a + i);
  dfs(0, -1, 0);
  
  int num = 0;
  for (int i = 0; i < N; i++) {
    for (int j = (PERIOD - 1) & (~i); j >= 0; j = (j - 1) & (~i)) {
      ans[j] ^= h[i];
    }
  }
  while (q--) {
    long long v;
    scanf("%lld", &v);
    v = (v - 1 + PERIOD) % PERIOD;
    printf("%lld\n", ans[v]);
  }
  return 0;
}