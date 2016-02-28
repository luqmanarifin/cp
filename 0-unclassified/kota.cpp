#include <bits/stdc++.h>

using namespace std;

const int MAX = 2000;
const int sh = 1000;
const int inf = 1e9;
const int N = 1e5 + 5;

struct segtree_up {
public:
  segtree_up() {
    a.resize(MAX << 2);
    build(1, 0, MAX);
  }
  void update(int at, int x, int y, int id) {
    update(1, 0, MAX, at, x, y, id);
  }
  pair<int, int> get(int l, int r) {
    return get(1, 0, MAX, l, r);
  }
private:
  void build(int p, int l, int r) {
    if(l == r) {
      a[p] = {inf, inf};
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    a[p] = min(a[p + p], a[p + p + 1]);
  }
  void update(int p, int l, int r, int at, int x, int y, int id) {
    if(l == r) {
      a[p] = min(a[p], {y - x, id});
      return;
    }
    int mid = (l + r) >> 1;
    if(at <= mid) {
      update(p + p, l, mid, at, x, y, id);
    } else {
      update(p + p + 1, mid + 1, r, at, x, y, id);
    }
    a[p] = min(a[p + p], a[p + p + 1]);
  }
  pair<int, int> get(int p, int l, int r, int ll, int rr) {
    if(rr < l || r < ll) return {inf, inf};
    if(ll <= l && r <= rr) return a[p];
    int mid = (l + r) >> 1;
    return min(get(p + p, l, mid, ll, rr), get(p + p + 1, mid + 1, r, ll, rr));
  }
  vector<pair<int, int>> a;
};

struct segtree_down {
public:
  segtree_down() {
    a.resize(MAX << 2);
    build(1, 0, MAX);
  }
  void update(int at, int x, int y, int id) {
    update(1, 0, MAX, at, x, y, id);
  }
  pair<int, int> get(int l, int r) {
    return get(1, 0, MAX, l, r);
  }
private:
  void build(int p, int l, int r) {
    if(l == r) {
      a[p] = {inf, inf};
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    a[p] = min(a[p + p], a[p + p + 1]);
  }
  void update(int p, int l, int r, int at, int x, int y, int id) {
    if(l == r) {
      a[p] = min(a[p], {-y - x, id});
      return;
    }
    int mid = (l + r) >> 1;
    if(at <= mid) {
      update(p + p, l, mid, at, x, y, id);
    } else {
      update(p + p + 1, mid + 1, r, at, x, y, id);
    }
    a[p] = min(a[p + p], a[p + p + 1]);
  }
  pair<int, int> get(int p, int l, int r, int ll, int rr) {
    if(rr < l || r < ll) return {inf, inf};
    if(ll <= l && r <= rr) return a[p];
    int mid = (l + r) >> 1;
    return min(get(p + p, l, mid, ll, rr), get(p + p + 1, mid + 1, r, ll, rr));
  }
  vector<pair<int, int>> a;
};

vector<tuple<int, int, int>> p;
vector<pair<int, int>> edge[N];
int par[N];
int a[N], b[N];
vector<tuple<int, int, int>> edges;

int find(int u) {
  return par[u] == u? u : par[u] = find(par[u]);
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

void add(int u, int v) {
  edges.emplace_back(abs(a[u] - a[v]) + abs(b[u] - b[v]), u, v);
}

int cmp_a(tuple<int, int, int> l, tuple<int, int, int> r) {
  int xl = get<0>(l);
  int yl = get<1>(l);
  int xr = get<0>(r);
  int yr = get<1>(r);
  if(yl != yr) return yl > yr;
  return xl < xr;
}

int cmp_b(tuple<int, int, int> l, tuple<int, int, int> r) {
  int xl = get<0>(l);
  int yl = get<1>(l);
  int xr = get<0>(r);
  int yr = get<1>(r);
  if(xl != xr) return xl < xr;
  return yl > yr;
}

int cmp_c(tuple<int, int, int> l, tuple<int, int, int> r) {
  int xl = get<0>(l);
  int yl = get<1>(l);
  int xr = get<0>(r);
  int yr = get<1>(r);
  if(yl != yr) return yl < yr;
  return xl < xr;
}

int cmp_d(tuple<int, int, int> l, tuple<int, int, int> r) {
  int xl = get<0>(l);
  int yl = get<1>(l);
  int xr = get<0>(r);
  int yr = get<1>(r);
  if(xl != xr) return xl < xr;
  return yl < yr;
}

int main() {
  for(int i = 0; i < N; i++) {
    par[i] = i;
  }
  
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &a[i], &b[i]);
    p.emplace_back(a[i], b[i], i);
  }
  sort(p.begin(), p.end());
  
  {
    sort(p.begin(), p.end(), cmp_a);
    segtree_up up;
    for(int i = 0; i < p.size(); i++) {
      int x, y, id;
      tie(x, y, id) = p[i];
      int some = x + y;
      pair<int, int> ret = up.get(0, some);
      if(ret.second != inf) {
        add(id, ret.second);
      }
      up.update(some, x, y, id);
    }
    
  }
  {
    sort(p.begin(), p.end(), cmp_b);
    segtree_up up;
    for(int i = 0; i < p.size(); i++) {
      int x, y, id;
      tie(x, y, id) = p[i];
      int some = x + y;
      pair<int, int> ret = up.get(some, MAX);
      if(ret.second != inf) {
        add(id, ret.second);
      }
      up.update(some, x, y, id);
    }
  }
  {
    sort(p.begin(), p.end(), cmp_c);
    segtree_down down;
    for(int i = 0; i < p.size(); i++) {
      int x, y, id;
      tie(x, y, id) = p[i];
      int some = x - y + sh;
      pair<int, int> ret = down.get(0, some);
      if(ret.second != inf) {
        add(id, ret.second);
      }
      down.update(some, x, y, id);
    }
  }
  {
    sort(p.begin(), p.end(), cmp_d);
    segtree_down down;
    for(int i = 0; i < p.size(); i++) {
      int x, y, id;
      tie(x, y, id) = p[i];
      int some = x - y + sh;
      pair<int, int> ret = down.get(some, MAX);
      if(ret.second != inf) {
        add(id, ret.second);
      }
      down.update(some, x, y, id);
    }
  }
  
  sort(edges.begin(), edges.end());
  long long ans = 0;
  int done = 0;
  for(auto it : edges) {
    int cost, u, v;
    tie(cost, u, v) = it;
    if(find(u) != find(v)) {
      ans += cost;
      done++;
    }
    merge(u, v);
  }
  assert(done == n - 1);
  cout << ans << endl;
  return 0;
}
