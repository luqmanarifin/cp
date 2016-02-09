#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int par[N];

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}

void join(int u, int v) {
  par[find(u)] = find(v);
}

struct segtree {
public:
  segtree(int _n) : n(_n) {
    good.resize(n << 2);
    build(1, 1, n);
  }
  void merge(int l, int r) {
    _merge(1, 1, n, l, r);
  }
private:
  void build(int p, int l, int r) {
    if(l == r) {
      good[p] = 1;
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
  }
  void _merge(int p, int l, int r, int ll, int rr) {
    if(good[p]) return;
    if(r < ll || rr < l) return;
    int mid = (l + r) >> 1;
    _merge(p + p, l, mid, ll, rr);
    _merge(p + p + 1, mid + 1, r, ll, rr);
    if(ll <= mid && mid < rr) join(mid, mid + 1);
    good[p] = good[p + p] && good[p + p + 1] && (find(l) == find(r));
  }
  vector<bool> good;
  int n;
};

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for(int i = 1; i <= n; i++) {
    par[i] = i;
  }
  segtree seg(n);
  while(q--) {
    int t, x, y;
    scanf("%d %d %d", &t, &x, &y);
    if(t == 1) {
      join(x, y);
    } else if(t == 2) {
      seg.merge(x, y);
    } else {
      puts(find(x) == find(y)? "YES" : "NO");
    }
  }
  
  return 0;
}
