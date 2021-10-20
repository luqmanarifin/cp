#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

struct Bit {
  Bit(int _n = 0) : n(_n) {
    a = vector<int>(n + 1, 0);
  };
  void add(int i, int x) {
    for (; i <= n; i |= i + 1) {
      a[i] += x;
    }
  }
  int find(int i) {
    i = min(i, n);
    int ret = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) {
      ret += a[i];
    }
    return ret;
  }
  int n;
  vector<int> a;
};

struct Rmq {
  Rmq(vector<int> a) : n(a.size()) {
    int bit = 0;
    while ((1 << (bit + 1)) <= n) bit++;
    rmq = vector<vector<int>>(n, vector<int>(bit + 1, 0));
    for (int i = 0; i < n; i++) {
      rmq[i][0] = a[i];
    }
    for (int j = 1; j <= bit; j++) {
      for (int i = 0; i + (1 << j) <= n; i++) {
        rmq[i][j] = max(rmq[i][j-1], rmq[i+(1<<(j-1))][j-1]);
      }
    }
  };
  int find(int l, int r) {
    if (l > r) return -1;
    int g = __builtin_clz(r - l + 1) ^ 31;
    return max(rmq[l][g], rmq[r-(1<<g)+1][g]);
  }
  int n;
  vector<vector<int>> rmq;
};

int best[N];  // length of A (non-zero)
set<int> cans;
Bit bit;

void add_can(int x) {
  bit.add(x, 1);
  cans.insert(x);
}

void remove_can(int x) {
  if (cans.count(x)) {
    bit.add(x, -1);
    cans.erase(x);
  }
}


struct Segtree {
  Segtree(vector<pair<int, int>> _a) : n(_a.size()), a(_a) {
    num.resize(n << 2);
    build(1, 0, n - 1);
  };
  void build(int p, int l, int r) {
    // printf("%d %d %d\n", p, l, r);
    num[p].resize(r - l + 1);
    for (int i = l; i <= r; i++) {
      num[p][i-l] = a[i];
    }
    sort(num[p].begin(), num[p].end());
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
  }
  int find(int l, int r, int x) {
    return find(1, 0, n - 1, l, r, x);
  }
  int find(int p, int l, int r, int ll, int rr, int x) {
    if (ll <= l && r <= rr) {
      int idx = lower_bound(num[p].begin(), num[p].end(), make_pair(x, -1)) - num[p].begin();
      return num[p].size() - idx;
    }
    int mid = (l + r) >> 1, ret = 0;
    if (ll <= mid) {
      ret += find(p + p, l, mid, ll, rr, x);
    }
    if (mid < rr) {
      ret += find(p + p + 1, mid + 1, r, ll, rr, x);
    }
    return ret;
  }
  void solve(int l, int r, int x, int val) {
    solve(1, 0, n - 1, l, r, x, val);
  }
  void solve(int p, int l, int r, int ll, int rr, int x, int val) {
    if (ll <= l && r <= rr) {
      int idx = lower_bound(num[p].begin(), num[p].end(), make_pair(x, -1)) - num[p].begin();
      for (int i = idx; i < num[p].size(); i++) {
        int len = x - num[p][i].second;
        if (val > best[len]) {
          best[len] = val;
          remove_can(len);
        }
      }
      return;
    }
    int mid = (l + r) >> 1;
    if (ll <= mid) {
      solve(p + p, l, mid, ll, rr, x, val);
    }
    if (mid < rr) {
      solve(p + p + 1, mid + 1, r, ll, rr, x, val);
    }
  }
  int n;
  vector<vector<pair<int, int>>> num;
  vector<pair<int, int>> a;
};

void clear(int na, int nb, int ns) {
  for (int i = 0; i <= na; i++) best[i] = 0;
  cans.clear();
}

vector<int> z_algorithm(string s, int cap) {
  int n = s.size(), L = 0, R = 0;
  vector<int> Z(n, 0);
  for (int i = 1; i < n; ++i) {
    if (i > R) {
      L = R = i;
      while (R < n && s[R] == s[R-L]) ++R;
      Z[i] = R-L; --R;
    }
    else {
      int k = i-L;
      if (Z[k] < R-i+1) Z[i] = Z[k];
      else {
        L = i;
        while (R < n && s[R] == s[R-L]) ++R;
        Z[i] = R-L; --R;
      }
    }
  }
  int mx = n - cap;
  vector<int> res(cap, 0);
  for (int i = 0; i < cap; i++) {
    res[i] = min(Z[mx + i], mx);
  }
  return res;
}

char buf[N];

tuple<string, int> read() {
  scanf("%s", buf);
  return make_tuple(string(buf), strlen(buf));
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    string a, b, s;
    int na, nb, ns;
    tie(a, na) = read();
    tie(b, nb) = read();
    tie(s, ns) = read();
    // puts("io done");
    clear(na, nb, ns);
    int log_n = (int) log2(ns);
    vector<int> za = z_algorithm(a + s, ns);
    vector<int> zb = z_algorithm(b + s, ns);
    int max_za = 0, max_zb = 0;
    for (auto it : za) max_za = max(max_za, it);
    for (auto it : zb) max_zb = max(max_zb, it);
    bit = Bit(max_za);
    for (int i = 1; i <= max_za; i++) {
      add_can(i);
    }
    vector<int> a_rmq;
    vector<pair<int, int>> a_segtree;
    for (int i = 0; i < ns; i++) {
      int until = min(ns - 1, i + za[i]);
      a_rmq.push_back(until);
      a_segtree.emplace_back(until, i);
    }
    Rmq rmq(a_rmq);
    // puts("build rmq done");
    Segtree seg(a_segtree);
    // puts("build segtree done");
    vector<pair<int, int>> ques;
    for (int i = 0; i < ns; i++) {
      ques.emplace_back(zb[i], i);
    }
    sort(ques.begin(), ques.end());
    reverse(ques.begin(), ques.end());
    for (auto it : ques) {
      int val = it.first;
      int at = it.second;
      if (val == 0 || cans.empty()) break;
      if (rmq.find(0, at - 1) < at) continue;
      int l = 0, r = at - 1;
      while (l < r) {
        int mid = (l + r) >> 1;
        if (rmq.find(0, mid) < at) {
          l = mid + 1;
        } else {
          r = mid;
        }
      }
      int last_hand = l;
      int segtree_iter = seg.find(last_hand, at - 1, at);
      int set_iter = bit.find(at - last_hand);
      if (segtree_iter + log_n*log_n < set_iter + log_n) {
        seg.solve(last_hand, at - 1, at, val);
      } else {
        vector<int> to_remove;
        for (auto it : cans) {
          if (at - it < last_hand) break;
          int now = at - it;
          if (now + za[now] >= at) {
            to_remove.push_back(it);
            best[it] = val;
          }
        }
        for (auto it : to_remove) remove_can(it);
      }
    }
    long long ans = max_za + max_zb + 1;
    for (int i = 1; i <= max_za; i++) {
      ans += best[i];
    }
    printf("%lld\n", ans);
  }
  return 0;
}
