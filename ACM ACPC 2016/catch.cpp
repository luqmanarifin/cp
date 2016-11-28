#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

struct node {
  node() {
    memset(a, 0, sizeof(a));
  }
  node(const node& other) {
    a[0] = other.a[0];
    a[1] = other.a[1];
  }
  node operator=(const node& other) {
    this->a[0] = other.a[0];
    this->a[1] = other.a[1];
    return *this;
  }
  bool get(int at) {
    return (a[at / 64] & (1LL << (at % 64))) != 0;
  }
  void set(int at, int i) {
    long long val = (1LL << (at % 64));
    if (i == 0) {
      a[at / 64] &= ~val;
    } else {
      a[at / 64] |= val;
    }
  }
  int count() {
    return __builtin_popcountll(a[0]) + __builtin_popcountll(a[1]);
  }
  node operator|(node other) {
    node ans;
    ans.a[0] = a[0] | other.a[0];
    ans.a[1] = a[1] | other.a[1];
    return ans;
  }
  long long a[2];
};

int x[N], y[N], k[N];

struct segtree {
  segtree(int n) {
    num.resize(n << 2);
    lef.resize(n << 2);
    rig.resize(n << 2);
    nod.resize(n << 2);
    build(1, 0, n - 1);
  }
  void build(int p, int l, int r) {
    num[p].resize(r - l + 1);
    nod[p].resize(r - l + 1);
    for (int i = 0; i < r - l + 1; i++) {
      nod[p][i].resize(r - l + 1);
    }
    lef[p] = x[l];
    rig[p] = x[r];
    if (l == r) {
      num[p][0] = y[l];
      nod[p][0][0].set(k[l], 1);
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    merge(num[p + p].begin(), num[p + p].end(), num[p + p + 1].begin(), num[p + p + 1].end(), num[p].begin());
    int cnt = r - l + 1;
    for (int i = 0; i < cnt; i++) {
      node now;
      for (int j = i; j < cnt; j++) {
        now.set(k[j], 1);
        nod[p][i][j] = now;
        //printf("%d %d %d: %d\n", p, i, j, nod[p][i][j].count());
      }
    }
  }
  
  int find(long long xa, long long xb, long long ya, long long yb) {
    return find(1, xa, xb, ya, xb).count();
  }
  node find(int p, long long xa, long long xb, long long ya, long long yb) {
    if (xa <= lef[p] && rig[p] <= xb) {
      int low = lower_bound(num[p].begin(), num[p].end(), ya) - num[p].begin();
      int upp = upper_bound(num[p].begin(), num[p].end(), yb) - num[p].begin() - 1;
      node ret;
      if (low > upp) {
        return ret;
      }
      return nod[p][low][upp];
    }
    if (rig[p] < xa || xb < lef[p]) {
      node ret;
      return ret;
    }
    node ret;
    ret = (ret | find(p + p, xa, xb, ya, yb));
    ret = (ret | find(p + p + 1, xa, xb, ya, yb));
    return ret;
  }
  vector<vector<int> > num;    // y coordinate
  vector<int> lef, rig;       // x coordinate
  vector<vector<vector<node> > > nod;
};

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, K;
    scanf("%d %d", &n, &K);
    vector<pair<pair<int, int>, int> > p;
    for (int i = 0; i < n; i++) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      w--;
      p.push_back(make_pair(make_pair(u, v), w));
    }
    sort(p.begin(), p.end());
    for (int i = 0; i < n; i++) {
      x[i] = p[i].first.first;
      y[i] = p[i].first.second;
      k[i] = p[i].second;
    }
    segtree seg(n);
    //cout << seg.find(0, 2, 0, 0) << endl;
    
    long long l = 0, r = 2e9;
    while (l < r) {
      long long mid = (l + r) >> 1;
      bool ada = 0;
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          if (k[i] == k[j]) continue;
          if (x[i] == x[j] || y[i] == y[j]) {
            long long xl = min(x[i], x[j]);
            long long xr = max(x[i], x[j]);
            long long yl = min(y[i], y[j]);
            long long yr = max(y[i], y[j]);
            if (yr - yl <= mid) {
              if (seg.find(xl, xl + mid, yl, yl + mid) == K) {
                ada = 1;
                goto BEST;
              }
              if (seg.find(xr - mid, xr, yl, yl + mid) == K) {
                ada = 1;
                goto BEST;
              }
              if (seg.find(xl, xl + mid, yr - mid, yr) == K) {
                ada = 1;
                goto BEST;
              }
              if (seg.find(xr - mid, xr, yr - mid, yr) == K) {
                ada = 1;
                goto BEST;
              }
            }
          } else {
            long long px = x[i];
            long long py = y[j];
            long long dirx = (px < x[j]? 1 : -1);
            long long diry = (py < y[j]? 1 : -1);
            long long xl = min(px, px + dirx * mid);
            long long xr = max(px, px + dirx * mid);
            long long yl = min(py, py + diry * mid);
            long long yr = max(py, py + diry * mid);
            if (seg.find(xl, xr, yl, yr) == K) {
              ada = 1;
              goto BEST;
            }
            
            px = x[i];
            py = y[j];
            dirx = (px < x[j]? 1 : -1);
            diry = (py < y[j]? 1 : -1);
            xl = min(px, px + dirx * mid);
            xr = max(px, px + dirx * mid);
            yl = min(py, py + diry * mid);
            yr = max(py, py + diry * mid);
            if (seg.find(xl, xr, yl, yr) == K) {
              ada = 1;
              goto BEST;
            }
          }
        }
      }
      BEST:;
      if (ada) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    printf("%d\n", l);
  }

  return 0;
}
