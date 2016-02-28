#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

struct segtree {
  segtree(int n) : n(n) {
    push.resize(n << 2);
    cnt.resize(n << 2);
    build(1, 0, n - 1);
  }
  int get(int l, int r) {
    return get(1, 0, n - 1, l, r);
  }
  void build(int p, int l, int r) {
    push[p] = -1;
    cnt[p] = r - l + 1;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
  }
  void relax(int p, int l, int r) {
    if(push[p] != -1) {
      cnt[p] = (push[p]? r - l + 1 : 0);
      if(l < r) {
        push[p + p] = push[p];
        push[p + p + 1] = push[p];
      }
      push[p] = -1;
    }
  }
  void combine(int p, int l, int r) {
    cnt[p] = cnt[p + p] + cnt[p + p + 1];
  }
  void change(int p, int l, int r, int ll, int rr, int val) {
    relax(p, l, r);
    if(r < ll || rr < l) return;
    if(ll <= l && r <= rr) {
      push[p] = val;
      relax(p, l, r);
      return;
    }
    int mid = (l + r) >> 1;
    change(p + p, l, mid, ll, rr, val);
    change(p + p + 1, mid + 1, r, ll, rr, val);
    combine(p, l, r);
  }
  int get(int p, int l, int r, int ll, int rr) {
    relax(p, l, r);
    if(r < ll || rr < l) return 0;
    if(ll <= l && r <= rr) return cnt[p];
    int mid = (l + r) >> 1;
    int ret = get(p + p, l, mid, ll, rr) + get(p + p + 1, mid + 1, rr, ll, rr);
    combine(p, l, r);
    return ret;
  }
  vector<int> push, cnt;
  int n;
};

int lef[N], rig[N], ptr, h[N], eu, pos[N];
vector<int> edge[N];
int rmq[N][20], n;

void dfs(int now) {
  lef[now] = ptr++;
  pos[now] = eu;
  rmq[eu++][0] = now;
  for(auto it : edge[now]) {
    h[it] = h[now] + 1;
    dfs(it);
    rmq[eu++][0] = now;
  }
  rig[now] = ptr - 1;
}

void build_lca() {
  for(int j = 1; (1 << j) <= eu; j++) {
    for(int i = 0; i + (1 << j) <= eu; i++) {
      rmq[i][j] = (h[rmq[i][j - 1]] < h[rmq[i+(1<<(j-1))][j - 1]]? rmq[i][j - 1] : rmq[i+(1<<(j-1))][j - 1]);
    }
  }
}

int lca(int u, int v) {
  int l = min(pos[u], pos[v]);
  int r = max(pos[u], pos[v]);
  int g = __builtin_clz(r - l + 1) ^ 31;
  return h[rmq[l][g]] < h[rmq[r-(1<<g)+1][g]]? rmq[l][g] : rmq[r-(1<<g)+1][g];
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    edge[a].push_back(b);
  }
  dfs(1);
  segtree seg(n);
  build_lca();
  assert(ptr == n);
  
  int q;
  scanf("%d", &q);
  while(q--) {
    int t, u, v;
    scanf("%d", &t);
    if(t == 1) {
      scanf("%d", &u);
      seg.change(1, 0, n - 1, lef[u], rig[u], 0);
      printf("%d\n", seg.get(0, n - 1));
    } else if(t == 2) {
      scanf("%d", &u);
      seg.change(1, 0, n - 1, lef[u], rig[u], 1);
      printf("%d\n", seg.get(0, n - 1));
    } else {
      scanf("%d %d", &u, &v);
      if(seg.get(lef[u], lef[u]) == 0 || seg.get(lef[v], lef[v]) == 0) {
        puts("Forgive me Sultan");
      } else {
        printf("%d\n", lca(u, v));
      }
    }
  }
  return 0;
}
