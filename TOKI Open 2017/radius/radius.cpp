#include "radius.h"

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct segtree {
  segtree() {}
  segtree(int n) : n(n) {
    num.resize(n << 2);
  }
  void update(int at, int val) {
    update(1, 0, n - 1, at, val);
  }
  void update(int p, int l, int r, int at, int val) {
    if (l == r) {
      num[p] = val;
      return;
    }
    int mid = (l + r) >> 1;
    if (at <= mid) {
      update(p + p, l, mid, at, val);
    } else {
      update(p + p + 1, mid + 1, r, at, val);
    }
    num[p] = max(num[p + p], num[p + p + 1]);
  }
  int find(int l, int r) {
    return find(1, 0, n - 1, l, r);
  }
  int find(int p, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) return num[p];
    if (r < ll || rr < l) return 0;
    int mid = (l + r) >> 1;
    return max(find(p+p, l, mid, ll, rr), find(p+p+1, mid + 1, r, ll, rr));
  }

  vector<int> num;
  int n;
};

segtree st, ch;
int ans[N], d[N], h[N];
vector<int> edge[N];

void dfs_pre(int now, int bef = -1) {
  if (bef >= 0) h[now] = h[bef] + 1;
  for (auto it : edge[now]) if (it != bef) {
    dfs_pre(it, now);
    d[now] = max(d[now], d[it] + 1);
  }
}

void dfs(int now, int bef = -1) {
  st.update(h[now], d[now] + h[now]);
  ch.update(h[now], d[now] + N - h[now]);
  int ret = 0;
  if (h[now] >= 2) {
    int len = h[now] / 2;
    int c = ch.find(h[now]-len+1, h[now]);
    ret = max(ret, c - N + h[now] + 1);
    ret = max(ret, st.find(0, h[now] - len));
  } else {
    ret = max(ret, st.find(0, h[now]));
  }
  ans[now] = ret;

  vector<int> kid, lef, rig;
  for (auto it : edge[now]) if (it != bef) {
    kid.push_back(it);
    lef.push_back(d[it] + 1);
    rig.push_back(d[it] + 1);
  }
  for (int i = 1; i < kid.size(); i++) lef[i] = max(lef[i], lef[i-1]);
  for (int i = (int) kid.size() - 2; i >= 0; i--) rig[i] = max(rig[i], rig[i+1]);
  for (int i = 0; i < kid.size(); i++) {
    int ot = 0;
    if (i - 1 >= 0) ot = max(ot, lef[i-1]);
    if (i + 1 < kid.size()) ot = max(ot, rig[i+1]);
    st.update(h[now], ot + h[now]);
    ch.update(h[now], ot + N - h[now]);
    dfs(kid[i], now);
  }
}

vector<int> getRadius(int n, int q, vector<int> u, vector<int> v, vector<int> a) {
  for (int i = 0; i < n - 1; i++) {
    u[i]--;
    v[i]--;
    edge[u[i]].push_back(v[i]);
    edge[v[i]].push_back(u[i]);
  }
  for (int i = 0; i < q; i++) {
    a[i]--;
  }
  st = segtree(n);
  ch = segtree(n);
  dfs_pre(0);
  dfs(0);
  //for (int i = 0; i < n; i++) printf("ans %d: %d\n", i, ans[i]);

  vector<int> ret;
  for (int i = 0; i < q; i++) ret.push_back(ans[a[i]]);
  return ret;
}
