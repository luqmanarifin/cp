#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

long long bit[N], sum[N];

void add_bit(int i, long long v, long long s) {
  for (; i < N; i |= i + 1) {
    bit[i] += v;
    sum[i] += s;
  }
}

void add(int l, int r, int val) {
  add_bit(l, val, -1LL * (l - 1) * val);
  add_bit(r + 1, -val, 1LL * r * val);
}

long long find_bit(int i) {
  int at = i;
  long long v = 0, s = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    v += bit[i];
    s += sum[i];
  }
  return at * v + s;
}

long long find(int l, int r) {
  return find_bit(r) - find_bit(l - 1);
}

int x[N];
vector<pair<int, int>> edge[N];

int ans[N], h[N];
long long pre[N];

void dfs(int now, int bef) {
  int p = lower_bound(pre, pre + h[now] + 1, pre[h[now]] - x[now]) - pre;
  if (p < h[now]) {
    //printf("%d %d\n", now, p);
    add(p, h[now] - 1, 1);
  }
  for (auto it : edge[now]) {
    int near = it.first;
    if (near == bef) continue;
    h[near] = h[now] + 1;
    pre[h[near]] = pre[h[now]] + it.second;
    dfs(near, now);
  }
  ans[now] = find(h[now], h[now]);
  add(h[now], h[now], -ans[now]);
}

int main() {
  freopen("car.in", "r", stdin);
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(bit, 0, sizeof(bit));
    memset(sum, 0, sizeof(sum));
    for (int i = 0; i < N; i++) edge[i].clear();
    
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", x + i);
    for (int i = 1; i < n; i++) {
      int u, v, c;
      scanf("%d %d %d", &u, &v, &c);
      edge[u].emplace_back(v, c);
      edge[v].emplace_back(u, c);
    }
    dfs(1, -1);
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]); printf("\n");
  }

  return 0;
}
