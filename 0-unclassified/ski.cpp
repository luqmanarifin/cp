#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

#define ii pair<long long, long long>
#define iii tuple<long long, long long, long long, long long>

struct segtree {
public:
  segtree(vector<long long> _num) {
    source = _num;
    n = source.size();
    tot.resize(n << 2);
    pl.resize(n << 2);
    pr.resize(n << 2);
    all.resize(n << 2);
    build(1, 1, n);
  }
  void update(int at, long long val) {
    _update(1, 1, n, at, val);
  }
  long long get_lef(int l, int r) {
    if(r < l || r < 1 || n < l) {
      return 0;
    }
    ii ret = _get_lef(1, 1, n, l, r);
    return max(ret.first, ret.second);
  }
  long long get_rig(int l, int r) {
    if(r < l || r < 1 || n < l) {
      return 0;
    }
    ii ret = _get_rig(1, 1, n, l, r);
    return max(ret.first, ret.second);
  }
  long long get_all(int l, int r) {
    if(r < l || r < 1 || n < l) {
      return 0;
    }
    iii ret = _get_all(1, 1, n, l, r);
    return max(get<0>(ret), max(get<1>(ret), max(get<2>(ret), get<3>(ret))));
  }
private:
  void combine(int p, int l, int r) {
    tot[p] = tot[p + p] + tot[p + p + 1];
    pl[p] = max(pl[p + p], tot[p + p] + pl[p + p + 1]);
    pr[p] = max(pr[p + p + 1], tot[p + p + 1] + pr[p + p]);
    all[p] = max(pr[p + p] + pl[p + p + 1], max(all[p + p], all[p + p + 1]));
  }
  void build(int p, int l, int r) {
    if(l == r) {
      tot[p] = source[l - 1];
      pl[p] = max(0LL, source[l - 1]);
      pr[p] = max(0LL, source[l - 1]);
      all[p] = max(0LL, source[l - 1]);
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    combine(p, l, r);
  }
  void _update(int p, int l, int r, int at, long long val) {
    if(l == r) {
      tot[p] = val;
      pl[p] = max(0LL, val);
      pr[p] = max(0LL, val);
      all[p] = max(0LL, val);
      return;
    }
    int mid = (l + r) >> 1;
    if(at <= mid) {
      _update(p + p, l, mid, at, val);
    } else {
      _update(p + p + 1, mid + 1, r, at, val);
    }
    combine(p, l, r);
  }
  ii _get_lef(int p, int l, int r, int ll, int rr) {
    if(r < ll || rr < l) {
      return make_pair(0, 0);
    }
    if(ll <= l && r <= rr) {
      return make_pair(pl[p], tot[p]);
    }
    int mid = (l + r) >> 1;
    ii lef = _get_lef(p + p, l, mid, ll, rr);
    ii rig = _get_lef(p + p + 1, mid + 1, r, ll, rr);
    return make_pair(max(lef.first, lef.second + rig.first), lef.second + rig.second);
  }
  ii _get_rig(int p, int l, int r, int ll, int rr) {
    if(r < ll || rr < l) {
      return make_pair(0, 0);
    }
    if(ll <= l && r <= rr) {
      return make_pair(pr[p], tot[p]);
    }
    int mid = (l + r) >> 1;
    ii lef = _get_rig(p + p, l, mid, ll, rr);
    ii rig = _get_rig(p + p + 1, mid + 1, r, ll, rr);
    return make_pair(max(rig.first, rig.second + lef.first), lef.second + rig.second);
  }
  iii _get_all(int p, int l, int r, int ll, int rr) {
    if(r < ll || rr < l) {
      return make_tuple(0, 0, 0, 0);
    }
    if(ll <= l && r <= rr) {
      return make_tuple(pl[p], pr[p], all[p], tot[p]);
    }
    int mid = (l + r) >> 1;
    iii lef = _get_all(p + p, l, mid, ll, rr);
    iii rig = _get_all(p + p + 1, mid + 1, r, ll, rr);
    long long r1 = max(get<0>(lef), get<3>(lef) + get<0>(rig));
    long long r2 = max(get<1>(rig), get<3>(rig) + get<1>(lef));
    long long r3 = max(get<1>(lef) + get<0>(rig), max(get<2>(lef), get<2>(rig)));
    return make_tuple(r1, r2, r3, get<3>(lef) + get<3>(rig));
  }
  int n;
  vector<long long> tot, pl, pr, all;
  vector<long long> source;
};

struct fenwick {
public:
  fenwick(vector<long long> s) : n(s.size()) {
    num.resize(n + 2);
    for(int i = 0; i < s.size(); i++) {
      add(i + 1, s[i]);
    }
  }
  void add(int at, long long val) {
    for(; at <= n; at |= at + 1) {
      num[at] += val;
    }
  }
  long long get(int l, int r) {
    return _get(r) - _get(l - 1);
  }
private:
  long long _get(int at) {
    long long sum = 0;
    for(; at >= 0; at = (at & (at + 1)) - 1) {
      sum += num[at];
    }
    return sum;
  }
  int n;
  vector<long long> num;
};

int h[N];

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for(int i = 0; i <= n; i++) {
    scanf("%d", h + i);
  }
  vector<long long> num, sum;
  for(int i = 1; i <= n; i++) {
    sum.push_back(h[i - 1] + h[i]);
    long long val = 1LL * (h[i - 1] - h[i]) * (h[i - 1] - h[i]);
    if(h[i - 1] < h[i]) {
      val = -val;
    }
    num.push_back(val);
  }
  
  segtree seg(num);
  fenwick fen(sum);
  
  while(q--) {
    int t, at;
    long long v;
    scanf("%d %d %lld", &t, &at, &v);
    if(t == 0) {
      if(at >= 1) {
        long long val = 1LL * (v - h[at - 1]) * (v - h[at - 1]);
        if(h[at - 1] < v) {
          val = -val;
        }
        seg.update(at, val);
      }
      if(at < n) {
        long long val = 1LL * (v - h[at + 1]) * (v - h[at + 1]);
        if(v < h[at + 1]) {
          val = -val;
        }
        seg.update(at + 1, val);
      }
      fen.add(at, -h[at]);
      fen.add(at, +v);
      fen.add(at + 1, -h[at]);
      fen.add(at + 1, +v);
      h[at] = v;
    } else {
      int l = at, r = n;
      while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(fen.get(at + 1, mid) <= v) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      printf("%lld\n", seg.get_all(1, l));
    }
  }
  return 0;
}
