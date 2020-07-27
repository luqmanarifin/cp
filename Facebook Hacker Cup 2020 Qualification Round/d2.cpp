#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;
const int N = 2e6 + 5;

struct segtree {
  segtree(int n) : n(n) {
    num.resize((n + 1) << 2);
    for (int i = 0; i < num.size(); i++) num[i] = INF;
  }
  void update(int at, long long val) {
    update(1, 0, n, at, val);
  }
  void update(int p, int l, int r, int at, long long val) {
    // printf("%d %d %d\n", l, r, at);
    if (l == r) {
      assert(at == l);
      num[p] = min(num[p], val);
      return;
    }
    int mid = (l + r) >> 1;
    if (at <= mid) {
      update(p + p, l, mid, at, val);
    }
    if (mid < at) {
      update(p + p + 1, mid + 1, r, at, val);
    }
    num[p] = min(num[p + p], num[p + p + 1]);
  }
  long long find(int l, int r) {
    return find(1, 0, n, l, r);
  }
  long long find(int p, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) return num[p];
    if (r < ll || rr < l) return INF;
    int mid = (l + r) >> 1;
    long long ret = INF;
    ret = min(ret, find(p + p, l, mid, ll, rr));
    ret = min(ret, find(p + p + 1, mid + 1, r, ll, rr));
    return ret;
  }
  int n;
  vector<long long> num;
};

// inti
bool is[N];
int idx[N], bef[N];

// cabang
int lvl[N], root[N];

vector<int> edge[N];
int p[N], c[N];
int n, m, a, b;

void init(int now, int depth) {
  idx[now] = depth;
  for (auto it : edge[now]) {
    if (idx[it] != -1) continue;
    bef[it] = now;
    init(it, depth + 1);
  }
}

void dfs(int now, int parent, int depth, int near) {
  if (is[now] && near) return;
  lvl[now] = depth;
  root[now] = parent;
  for (auto it : edge[now]) {
    if (it == near) continue;
    dfs(it, parent, depth + 1, now);
  }
}

void solve(int now, int near, segtree *seg) {
  if (is[now] && near) return;
  if (lvl[now] > m) return;
  if (c[now]) {
    int l = idx[root[now]];
    int r = idx[root[now]] + m - lvl[now];
    long long cur = seg->find(l, r) + c[now];
    seg->update(idx[root[now]] + lvl[now], cur);
    // printf("now %d root %d update at %d, val %lld\n", now, root[now], idx[root[now]] + lvl[now], cur);
  }
  for (auto it : edge[now]) {
    if (it == near) continue;
    solve(it, now, seg);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    memset(is, 0, sizeof(is));
    memset(idx, -1, sizeof(idx));
    for (int i = 0; i < N; i++) edge[i].clear();

    scanf("%d %d %d %d", &n, &m, &a, &b);
    for (int i = 1; i <= n; i++) {
      scanf("%d %d", p + i, c + i);
      if (p[i] != 0) {
        edge[i].push_back(p[i]);
        edge[p[i]].push_back(i);
      }
    }
    init(b, 0);
    int now = a;
    while (now != b) {
      is[now] = 1;
      now = bef[now];
    }
    is[b] = 1;

    now = a;
    while (now != b) {
      dfs(now, now, 0, 0);
      now = bef[now];
    }
    dfs(now, now, 0, 0);

    segtree seg(2 * n);
    seg.update(idx[a], 0);

    now = a;
    while (now != b) {
      // printf("solving %d\n", now);
      solve(now, 0, &seg);
      now = bef[now];
    }
    solve(now, 0, &seg);

    long long ans = seg.find(0, m);
    if (ans >= INF) ans = -1;
    printf("Case #%d: %lld\n", tt, ans);
    cerr << tt << " done!" << endl;
  }

  return 0;
}
