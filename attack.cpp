#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

vector<int> edge[N];
vector<int> at[N];
int par[N];

int find(int u) {
  return par[u] == u? u : par[u] = find(par[u]);
}

void join(int u, int v) {
  par[find(u)] = find(v);
}

class segtree {
public:
  segtree(int _n) : n(_n) {
    good.resize(n << 2);
    build(1, 1, n);
  }
  void merge(int l, int r) {
    assert(l <= r);
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
  int n;
  vector<int> good;
};

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  while(m--) {
    int a, b;
    scanf("%d %d", &a, &b);
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  for(int i = 0; i < N; i++) {
    par[i] = i;
  }
  segtree seg(n);
  for(int i = 1; i <= n; i++) {
    edge[i].push_back(0);
    edge[i].push_back(n + 1);
    sort(edge[i].begin(), edge[i].end());
    for(int j = 1; j < edge[i].size(); j++) {
      if(edge[i][j - 1] + 1 <= edge[i][j] - 1) {
        seg.merge(edge[i][j - 1] + 1, edge[i][j] - 1);
        join(i, edge[i][j] - 1);
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    at[find(i)].push_back(i);
  }
  int groups = 0;
  for(int i = 1; i <= n; i++) {
    if(at[i].size()) {
      groups++;
    }
  }
  printf("%d\n", groups);
  for(int i = 1; i <= n; i++) {
    if(at[i].size()) {
      printf("%d ", at[i].size());
      for(auto it : at[i]) {
        printf("%d ", it);
      }
      printf("\n");
    }
  }
  return 0;
}
