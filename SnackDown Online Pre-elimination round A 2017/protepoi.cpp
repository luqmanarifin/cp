#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
const int N = 4e5 + 5;

struct segtree {
  segtree(int n) : n(n) {
    num.assign(n << 2, inf);
    update(0, 0);
  }
  void update(int at, int val) {
    update(1, 0, n - 1, at, val);
  }
  void update(int p, int l, int r, int at, int val) {
    if (l == r) {
      num[p] = min(num[p], val);
      return;
    }
    int mid = (l + r) >> 1;
    if (at <= mid) {
      update(p + p, l, mid, at, val);
    } else {
      update(p + p + 1, mid + 1, r, at, val);
    }
    num[p] = min(num[p + p], num[p + p + 1]);
  }
  int find(int l, int r) {
    return find(1, 0, n - 1, l, r);
  }
  int find(int p, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) return num[p];
    if (r < ll || rr < l) return inf;
    int mid = (l + r) >> 1;
    return min(find(p + p, l, mid, ll, rr), find(p + p + 1, mid + 1, r, ll, rr));
  }
  vector<int> num;
  int n;
};

vector<int> px, py;
vector<pair<int, int>> sx, sy;
map<int, int> mpx, mpy;
int n, k, m;

vector<int> tox[N], toy[N];

void add_x(int lef, int rig) {
  sx.emplace_back(lef, rig);
  px.push_back(lef);
  px.push_back(lef - 1);
  px.push_back(rig);
  if (rig + 1 <= k) {
    px.push_back(rig + 1);
  }
}

void add_y(int lef, int rig) {
  sy.emplace_back(lef, rig);
  py.push_back(lef);
  py.push_back(lef - 1);
  py.push_back(rig);
  if (rig + 1 <= k) {
    py.push_back(rig + 1);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < N; i++) {
      tox[i].clear();
      toy[i].clear();
    }
    px.clear();
    py.clear();
    sx.clear();
    sy.clear();
    mpx.clear();
    mpy.clear();
    
    scanf("%d %d %d", &n, &k, &m);
    px.push_back(0);
    px.push_back(k);
    py.push_back(0);
    py.push_back(k);
    int lo = (n - k) / 2;
    int hi = (n + k) / 2;
    
    
    while (m--) {
      pair<int, int> l, r;
      scanf("%d %d %d %d", &l.first, &l.second, &r.first, &r.second);
      if (l > r) swap(l, r);
      if (lo < l.first && l.first <= hi) {
        int lef = l.first - lo;
        int rig = min(k, r.first - lo);
        add_x(lef, rig);
      } else if (lo < l.second && l.second <= hi) {
        int lef = l.second - lo;
        int rig = min(k, r.second - lo);
        add_y(lef, rig);
      } else if (l.first <= lo && l.second <= lo) {
        if (l.first == r.first) {
          if (lo < r.second) {
            add_y(1, r.second - lo);
          }
        } else {
          if (lo < r.first) {
            add_x(1, r.first - lo);
          }
        }
      } else if (l.first <= lo) {
        if (lo < r.first) {
          add_x(1, r.first - lo);
        }
      } else if (l.second <= lo) {
        if (lo < r.second) {
          add_y(1, r.second - lo);
        }
      }
    }
    sort(px.begin(), px.end());
    sort(py.begin(), py.end());
    px.resize(distance(px.begin(), unique(px.begin(), px.end())));
    py.resize(distance(py.begin(), unique(py.begin(), py.end())));
    for (int i = 0; i < px.size(); i++) mpx[px[i]] = i;
    for (int i = 0; i < py.size(); i++) mpy[py[i]] = i;
    for (int i = 0; i < sx.size(); i++) {
      int l, r;
      tie(l, r) = sx[i];
      tox[mpx[l]].push_back(mpx[r]);
    }
    for (int i = 0; i < sy.size(); i++) {
      int l, r;
      tie(l, r) = sy[i];
      toy[mpy[l]].push_back(mpy[r]);
    }
    segtree segx(px.size());
    segtree segy(py.size());
    for (int i = 1; i < px.size(); i++) {
      for (auto it : tox[i]) {
        int bef = segx.find(i - 1, it);
        segx.update(it, bef + 1);
      }
    }
    for (int i = 1; i < py.size(); i++) {
      for (auto it : toy[i]) {
        int bef = segy.find(i - 1, it);
        segy.update(it, bef + 1);
      }
    }
    int ans = segx.find(px.size() - 1, px.size() - 1) + segy.find(py.size() - 1, py.size() - 1);
    if (ans >= inf) ans = -1;
    printf("%d\n", ans);
  }

  return 0;
}
