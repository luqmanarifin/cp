#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];
vector<int> num[N << 2];

void build(int p, int l, int r) {
  num[p].resize(r - l + 1);
  if (l == r) {
    num[p][0] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(p + p, l, mid);
  build(p + p + 1, mid + 1, r);
  merge(num[p + p].begin(), num[p + p].end(), num[p + p + 1].begin(), num[p + p + 1].end(), num[p].begin());
}

int find(int p, int l, int r, int ll, int rr, int k) {
  if (ll <= l && r <= rr) {
    return lower_bound(num[p].begin(), num[p].end(), k) - num[p].begin();
  }
  if (r < ll || rr < l) return 0;
  int mid = (l + r) >> 1;
  return find(p + p, l, mid, ll, rr, k) + find(p + p + 1, mid + 1, r, ll, rr, k);
}

int l[N], r[N];
int v[N], cnt;
vector<int> edge[N];

void dfs(int now) {
  l[now] = r[now] = cnt++;
  for (auto it : edge[now]) {
    dfs(it);
    r[now] = cnt - 1;
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    cnt = 0;
    for (int i = 0; i < N; i++) edge[i].clear();

    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
      int par;
      scanf("%d", &par);
      edge[par].push_back(i);
    }
    for (int i = 1; i <= n; i++) scanf("%d", v + i);
    dfs(1);
    for (int i = 1; i <= n; i++) a[l[i]] = v[i];
    build(1, 0, n - 1);
    //for (int i = 1; i <= n; i++) printf("%d %d %d\n", i, l[i], r[i]);
    //for (int i = 0; i < n; i++) printf("%d ", a[i]); printf("\n");
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      long long ret = find(1, 0, n - 1, l[i], r[i], v[i]);
      ans += ret * (ret - 1) / 2;
    }
    printf("%lld\n", ans);
  }

  return 0;
}