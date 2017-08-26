#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

const double PI = acos(-1.0);
const double SAVE = 20 - PI * 5;

struct segtree {
  segtree(int n) : n(n) {
    num.assign(n << 2, -1e18);
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
    int mid = (l + r) >> 1;
    int ret = 0;
    if (ll <= mid) {
      ret = max(ret, find(p + p, l, mid, ll, rr));
    }
    if (mid < rr) {
      ret = max(ret, find(p + p + 1, mid + 1, r, ll, rr));
    }
    return ret;
  }
  int n;
  vector<double> num;
};

map<int, int> idx, idy;
set<int> alx, aly;

pair<int, int> a[N], from, to;
int n;
#define x first
#define y second

void reverse_x() {
  for (int i = 0; i < n; i++) {
    a[i].x = alx.size() - a[i].x - 1;
  }
  from.x = alx.size() - from.x - 1;
  to.x = alx.size() - to.x - 1;
}

void reverse_y() {
  for (int i = 0; i < n; i++) {
    a[i].y = aly.size() - a[i].y - 1;
  }
  from.y = aly.size() - from.y - 1;
  to.y = aly.size() - to.y - 1;
}

void encode(pair<int, int>& p) {
  p.x = idx[p.x];
  p.y = idy[p.y];
}

int main() {
  scanf("%d %d %d %d", &from.x, &from.y, &to.x, &to.y);
  alx.insert(from.x);
  aly.insert(from.y);
  alx.insert(to.x);
  aly.insert(to.y);
  
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &a[i].x, &a[i].y);
    alx.insert(a[i].x);
    aly.insert(a[i].y);
  }
  
  int id = 0;
  for (auto it : alx) {
    idx[it] = id++;
  }
  id = 0;
  for (auto it : aly) {
    idy[it] = id++;
  }
  
  encode(from);
  encode(to);
  for (int i = 0; i < n; i++) encode(a[i]);
  
  if (from.x > to.x) reverse_x();
  if (from.y > to.y) reverse_y();
  
  a[n] = from;
  a[n + 1] = to;
  sort(a, a + n + 2);
  
  int best = 0;
  for (int i = 0; i < n + 2; i++) {
    if (a[i] == from) {
      
    }
    if (a[i] == to) {
      
    }
  }
  return 0;
}
