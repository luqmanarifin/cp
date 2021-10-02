#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int inf = 1e9;

typedef pair<int, int> point;
#define x first
#define y second

struct segtree {
  segtree() {}
  segtree(vector<int> a) : a(a), n(a.size()) {
    num.resize(a.size() << 2, -inf);
    push.resize(a.size() << 2, -1);
  }
  void update(int at, int val) {
    update(1, 0, n - 1, at, val);
  }
  void update(int p, int l, int r, int at, int val) {
    lazy(p, l, r);
    if (a[l] <= at && at <= a[r]) {
      push[p] = max(push[p], val);
      lazy(p, l, r);
      return;
    }
    if (at < a[l] || a[r] < at) return;
    int mid = (l + r) >> 1;
    update(p + p, l, mid, at, val);
    update(p + p + 1, mid + 1, r, at, val);
    num[p] = max(num[p + p], num[p + p + 1]);
  }
  void lazy(int p, int l, int r) {
    if (push[p] != -1) {
      num[p] = max(num[p], push[p]);
      if (l < r) {
        push[p + p] = max(push[p + p], push[p]);
        push[p + p + 1] = max(push[p + p + 1], push[p]);
      }
      push[p] = -1;
    }
  }
  int find(int l, int r) {
    return find(1, 0, n - 1, l, r);
  }
  int find(int p, int l, int r, int ll, int rr) {
    lazy(p, l, r);
    if (ll <= a[l] && a[r] <= rr) return num[p];
    if (a[r] < ll || rr < a[l]) return -inf;
    int mid = (l + r) >> 1;
    return max(find(p + p, l, mid, ll, rr), find(p + p + 1, mid + 1, r, ll, rr));
  }
  vector<int> a, num, push;
  int n;
};

vector<int> make_unique(vector<int> q) {
  sort(q.begin(), q.end());
  q.resize(distance(q.begin(), unique(q.begin(), q.end())));
  return q;
}

vector<int> merge(vector<int> a, vector<int> b) {
  vector<int> ret;
  for (auto it : a) ret.push_back(it);
  for (auto it : b) ret.push_back(it);
  return make_unique(ret);
}

struct big_segtree {
  big_segtree(vector<point> p) {
    for (auto it : p) px.push_back(it.x);
    px = make_unique(px);
    n = px.size();
    num.resize(n << 2);
    numpy.resize(n << 2);
    py.resize(n);
    int now = 0;
    for (int i = 0; i < p.size(); i++) {
      int j = i;
      while (j + 1 < p.size() && p[j + 1].x == p[j].x) j++;
      for (int k = i; k <= j; k++) py[now].push_back(p[k].y);
      py[now] = make_unique(py[now]);
      i = j;
      now++;
    }
    // printf("px "); for (auto it : px) printf("%d ", it); printf("\n");
    // printf("py\n"); for (auto it : py) {
    //   for (auto j : it) printf("%d ", j);
    //   printf("\n");
    // }
    build(1, 0, n - 1);
  }
  void build(int p, int l, int r) {
    if (l == r) {
      num[p] = segtree(py[l]);
      numpy[p] = py[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    numpy[p] = merge(numpy[p + p], numpy[p + p + 1]);
    num[p] = segtree(numpy[p]);
  }
  void update(point at, int val) {
    update(1, 0, n - 1, at, val);
  }
  void update(int p, int l, int r, point at, int val) {
    num[p].update(at.y, val);
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (at.x <= px[mid]) {
      return update(p + p, l, mid, at, val);
    } else {
      return update(p + p + 1, mid + 1, r, at, val);
    }
  }
  int find(point ll, point rr) {
    return find(1, 0, n - 1, ll, rr);
  }
  int find(int p, int l, int r, point ll, point rr) {
    if (ll.x <= px[l] && px[r] <= rr.x) return num[p].find(min(ll.y, rr.y), max(ll.y, rr.y));
    if (px[r] < ll.x || rr.x < px[l]) return -inf;
    int mid = (l + r) >> 1;
    return max(find(p + p, l, mid, ll, rr), find(p + p + 1, mid + 1, r, ll, rr));
  }
  vector<segtree> num;
  vector<vector<int>> numpy;
  vector<int> px;
  vector<vector<int>> py;
  int n;
};

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  vector<point> p;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    p.emplace_back(a[i] - i, a[i]);
  }
  sort(p.begin(), p.end());
  big_segtree seg(p);
  for (int i = 1; i <= n; i++) {
    if (a[i] <= i) {
      int xl = a[i] - i;
      int xr = inf;
      int yl = -inf;
      int yr = a[i] - 1;
      int val = seg.find({xl, yl}, {xr, yr});
      // printf("query from %d %d: %d %d\n", xl, yl, xr, yr);
      // printf("get %d: %d\n", i, val);
      int cur = max(1, val + 1);
      // printf("update %d: %d\n", i, cur);
      seg.update({a[i] - i, a[i]}, cur);
    }
  }
  cout << seg.find({-inf, -inf}, {inf, inf}) << endl;
  return 0;
}
