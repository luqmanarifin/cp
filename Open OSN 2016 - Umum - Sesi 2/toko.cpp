#include <bits/stdc++.h>

using namespace std;

const int MAX = 4100;
const int sh = 2000;
const int inf = 1e9;
const int N = 6e5 + 5;

struct segtree_up {
public:
  segtree_up() {
    a.resize(MAX << 2);x
    build(1, 0, MAX);
  }
  void update(int at, int x, int y, int id) {
    update(1, 0, MAX, at, x, y, id);
  }
  pair<int, int> get(int l, int r) {
    return get(1, 0, MAX, l, r);
  }
private:
  void combine(int p) {
    a[p] = min(a[p + p], a[p + p + 1]);
    if(a[p + p].first == a[p + p + 1].first) {
      a[p].second = -1;
    }
  }
  void build(int p, int l, int r) {
    if(l == r) {
      a[p] = {inf, inf};
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    combine(p);
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
    combine(p);
  }
  pair<int, int> get(int p, int l, int r, int ll, int rr) {
    if(rr < l || r < ll) return {inf, inf};
    if(ll <= l && r <= rr) return a[p];
    int mid = (l + r) >> 1;
    return min(get(p + p, l, mid, ll, rr), get(p + p + 1, mid + 1, r, ll, rr));
  }
  vector<pair<int, int>> a;
};

struct segtree_up_rev {
public:
  segtree_up_rev() {
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
  void combine(int p) {
    a[p] = max(a[p + p], a[p + p + 1]);
    if(a[p + p].first == a[p + p + 1].first) {
      a[p].second = -1;
    }
  }
  void build(int p, int l, int r) {
    if(l == r) {
      a[p] = {-inf, -inf};
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    combine(p);
  }
  void update(int p, int l, int r, int at, int x, int y, int id) {
    if(l == r) {
      a[p] = max(a[p], {y - x, id});
      return;
    }
    int mid = (l + r) >> 1;
    if(at <= mid) {
      update(p + p, l, mid, at, x, y, id);
    } else {
      update(p + p + 1, mid + 1, r, at, x, y, id);
    }
    combine(p);
  }
  pair<int, int> get(int p, int l, int r, int ll, int rr) {
    if(rr < l || r < ll) return {-inf, -inf};
    if(ll <= l && r <= rr) return a[p];
    int mid = (l + r) >> 1;
    return max(get(p + p, l, mid, ll, rr), get(p + p + 1, mid + 1, r, ll, rr));
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
  void combine(int p) {
    a[p] = min(a[p + p], a[p + p + 1]);
    if(a[p + p].first == a[p + p + 1].first) {
      a[p].second = -1;
    }
  }
  void build(int p, int l, int r) {
    if(l == r) {
      a[p] = {inf, inf};
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    combine(p);
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
    combine(p);
  }
  pair<int, int> get(int p, int l, int r, int ll, int rr) {
    if(rr < l || r < ll) return {inf, inf};
    if(ll <= l && r <= rr) return a[p];
    int mid = (l + r) >> 1;
    return min(get(p + p, l, mid, ll, rr), get(p + p + 1, mid + 1, r, ll, rr));
  }
  vector<pair<int, int>> a;
};

struct segtree_down_rev {
public:
  segtree_down_rev() {
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
  void combine(int p) {
    a[p] = max(a[p + p], a[p + p + 1]);
    if(a[p + p].first == a[p + p + 1].first) {
      a[p].second = -1;
    }
  }
  void build(int p, int l, int r) {
    if(l == r) {
      a[p] = {-inf, -inf};
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    combine(p);
  }
  void update(int p, int l, int r, int at, int x, int y, int id) {
    if(l == r) {
      a[p] = max(a[p], {-y - x, id});
      return;
    }
    int mid = (l + r) >> 1;
    if(at <= mid) {
      update(p + p, l, mid, at, x, y, id);
    } else {
      update(p + p + 1, mid + 1, r, at, x, y, id);
    }
    combine(p);
  }
  pair<int, int> get(int p, int l, int r, int ll, int rr) {
    if(rr < l || r < ll) return {-inf, -inf};
    if(ll <= l && r <= rr) return a[p];
    int mid = (l + r) >> 1;
    return max(get(p + p, l, mid, ll, rr), get(p + p + 1, mid + 1, r, ll, rr));
  }
  vector<pair<int, int>> a;
};

vector<tuple<int, int, int>> p;
int a[N], b[N];
vector<pair<int, int>> can[2 * N + 15];
char s[2005][2005], junk[20];

int dad[N];                         // id node terdekat
int qa[N], qb[N];
int nearest[N];                     // -1 if ga ada yg deket

bool super[N];
vector<int> edge[N];
int ans[N];

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

void process() {
  {
    sort(p.begin(), p.end(), cmp_a);
    segtree_up up;
    for(int i = 0; i < p.size(); i++) {
      int x, y, id;
      tie(x, y, id) = p[i];
      int some = x + y;
      pair<int, int> ret = up.get(0, some);
      int now = y - x;
      if(abs(ret.first) != inf) {
        can[id].emplace_back(abs(now - ret.first), ret.second);
      }
      if(id < N) up.update(some, x, y, id);
    }
  }
  {
    sort(p.begin(), p.end(), cmp_a);
    reverse(p.begin(), p.end());
    segtree_up_rev up;
    for(int i = 0; i < p.size(); i++) {
      int x, y, id;
      tie(x, y, id) = p[i];
      int some = x + y;
      pair<int, int> ret = up.get(some, MAX);
      int now = y - x;
      if(abs(ret.first) != inf) {
        can[id].emplace_back(abs(now - ret.first), ret.second);
      }
      if(id < N) up.update(some, x, y, id);
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
      int now = y - x;
      if(abs(ret.first) != inf) {
        can[id].emplace_back(abs(now - ret.first), ret.second);
      }
      if(id < N) up.update(some, x, y, id);
    }
  }
  {
    sort(p.begin(), p.end(), cmp_b);
    reverse(p.begin(), p.end());
    segtree_up_rev up;
    for(int i = 0; i < p.size(); i++) {
      int x, y, id;
      tie(x, y, id) = p[i];
      int some = x + y;
      pair<int, int> ret = up.get(0, some);
      int now = y - x;
      if(abs(ret.first) != inf) {
        can[id].emplace_back(abs(now - ret.first), ret.second);
      }
      if(id < N) up.update(some, x, y, id);
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
      int now = -y - x;
      if(abs(ret.first) != inf) {
        can[id].emplace_back(abs(now - ret.first), ret.second);
      }
      if(id < N) down.update(some, x, y, id);
    }
  }
  {
    sort(p.begin(), p.end(), cmp_c);
    reverse(p.begin(), p.end());
    segtree_down_rev down;
    for(int i = 0; i < p.size(); i++) {
      int x, y, id;
      tie(x, y, id) = p[i];
      int some = x - y + sh;
      pair<int, int> ret = down.get(some, MAX);
      int now = -y - x;
      if(abs(ret.first) != inf) {
        can[id].emplace_back(abs(now - ret.first), ret.second);
      }
      if(id < N) down.update(some, x, y, id);
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
      int now = -y - x;
      if(abs(ret.first) != inf) {
        can[id].emplace_back(abs(now - ret.first), ret.second);
      }
      if(id < N) down.update(some, x, y, id);
    }
  }
  {
    sort(p.begin(), p.end(), cmp_d);
    reverse(p.begin(), p.end());
    segtree_down_rev down;
    for(int i = 0; i < p.size(); i++) {
      int x, y, id;
      tie(x, y, id) = p[i];
      int some = x - y + sh;
      pair<int, int> ret = down.get(0, some);
      int now = -y - x;
      if(abs(ret.first) != inf) {
        can[id].emplace_back(abs(now - ret.first), ret.second);
      }
      if(id < N) down.update(some, x, y, id);
    }
  }
}

void dfs(int now, int id) {
  ans[now] = id;
  for(auto it : edge[now]) {
    dfs(it, id);
  }
}

int main() {
  int n, m, k, q;
  scanf("%s %d %d %d %d", junk, &n, &m, &k, &q);
  int aw = 0;
  for(int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
    for(int j = 1; j <= m; j++) {
      if(s[i][j] == 'X') {
        ++aw;
        a[aw] = i;
        b[aw] = j;
        p.emplace_back(i, j, aw);
      }
    }
  }
  //puts("read done");
  assert(aw == k);
  process();
  //puts("process done");
  for(int i = 1; i <= k; i++) {
    sort(can[i].begin(), can[i].end());
    can[i].resize(distance(can[i].begin(), unique(can[i].begin(), can[i].end())));
    //printf("can %d ada %d:\n", i, can[i].size());
    //for(auto it : can[i]) printf("%d %d\n", it.first, it.second);
    if((can[i].size() >= 2 && can[i][0].first == can[i][1].first) || can[i][0].second == -1) {
      
    } else {
      dad[i] = can[i][0].second;
    }
    can[i].clear();
  }
  //puts("dad done");
  // read query
  for(int i = 1; i <= q; i++) {
    //if(i % 10000 == 0) printf("read query %d\n", i);
    scanf("%d %d", &qa[i], &qb[i]);
    //printf("baca %d %d\n", qa[i], qb[i]);
    p.emplace_back(qa[i], qb[i], N + i);
  }
  //puts("read query done");
  process();
  //puts("process query done");
  for(int i = N + 1; i <= N + q; i++) {
    sort(can[i].begin(), can[i].end());
    can[i].resize(distance(can[i].begin(), unique(can[i].begin(), can[i].end())));
    //printf("can %d ada %d:\n", i - N, can[i].size());
    //for(auto it : can[i]) printf("%d %d\n", it.first, it.second);
    if((can[i].size() >= 2 && can[i][0].first == can[i][1].first) || can[i][0].second == -1) {
      nearest[i - N] = -1;
    } else {
      nearest[i - N] = can[i][0].second;
    }
  }
  //puts("nearest done");
  for(int i = 1; i <= k; i++) {
    int id = dad[i];
    if(id) {
      if(dad[id] == i) {
        super[i] = super[id] = 1;
      } else {
        edge[id].push_back(i);
      }
    }
  }
  for(int i = 1; i <= k; i++) {
    if(super[i]) {
      dfs(dad[i], i);
    } else if(dad[i] == 0) {
      dfs(i, i);
    }
  }
  for(int i = 1; i <= q; i++) {
    if(nearest[i] == -1) {
      printf("%d %d\n", qa[i], qb[i]);
    } else {
      printf("%d %d\n", a[ans[nearest[i]]], b[ans[nearest[i]]]);
    }
  }
  //printf("dad: "); for(int i = 1; i <= k; i++) printf("%d ", dad[i]); printf("\n");
  //printf("nearest: "); for(int i = 1; i <= q; i++) printf("%d ", nearest[i]); printf("\n");
  return 0;
}

