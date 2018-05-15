#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

vector<int> edge[N];
int p[N], cnt[N];

// u bawah, v atas, 0 kalo ga ada apa2
int is_parent(int u, int v) {
  if (p[u] == v) return u;
  if (u == 0) return 0;
  return is_parent(p[u], v);
}

void dfs(int now, int bef) {
  p[now] = bef;
  cnt[now] = 1;
  for (auto it : edge[now]) {
    if (it == bef) continue;
    dfs(it, now);
    cnt[now] += cnt[it];
  }
}

int main() {
  int n, f, b;
  scanf("%d %d %d", &n, &f, &b);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  dfs(1, 0);
  long long ans = 0;
  int root = -1;
  if (root = is_parent(f, b)) {
    ans = 1LL * n * (n - 1) - 1LL * cnt[f] * (n - cnt[root]);
  } else if (root = is_parent(b, f)) {
    ans = 1LL * n * (n - 1) - 1LL * cnt[b] * (n - cnt[root]);
  } else {
    ans = 1LL * n * (n - 1) - 1LL * cnt[b] * cnt[f];
  }
  cout << ans << endl;
  return 0;
}
