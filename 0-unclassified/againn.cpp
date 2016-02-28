#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6;
const long long mod = 1e9 + 7;

long long power(int a, int b) {
  long long ret = 1;
  for(int i = 0; i < b; i++) {
    ret = ret * a % mod;
  }
  return ret;
}

long long will[4];

struct segtree {
  segtree() {
    for(int i = 0; i < 4; i++) {
      sum[i].resize(MAX << 2);
      push[i].resize(MAX << 2);
    }
    ada.resize(MAX << 2);
    ans.resize(MAX << 2);
    build(1, 0, MAX - 1);
  }
  void refresh() {
    for(int i = 0; i < 4; i++) {
      push[i].assign(MAX << 2, 0);
    }
    ada.assign(MAX << 2, 0);
    ans.assign(MAX << 2, 0);
  }
  void relax(int p, int l, int r) {
    if(ada[p]) {
      for(int i = 0; i < 4; i++) {
        ans[p] = (ans[p] + sum[i][p] * push[i][p]) % mod;
        if(l < r) {
          push[i][p + p] = (push[i][p + p] + push[i][p]) % mod;
          push[i][p + p + 1] = (push[i][p + p + 1] + push[i][p]) % mod;
        }
        push[i][p] = 0;
      }
      if(l < r) {
        ada[p + p] = ada[p + p + 1] = 1;
      }
      ada[p] = 0;
    }
  }
  void combine(int p) {
    ans[p] = (ans[p + p] + ans[p + p + 1]) % mod;
  }
  void build(int p, int l, int r) {
    if(l == r) {
      for(int i = 0; i < 4; i++) {
        sum[i][p] = power(l, i);
      }
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    for(int i = 0; i < 4; i++) {
      sum[i][p] = (sum[i][p + p] + sum[i][p + p + 1]) % mod;
    }
  }
  void add(int l, int r) {
    add(1, 0, MAX - 1, l, r);
  }
  void add(int p, int l, int r, int ll, int rr) {
    relax(p, l, r);
    if(r < ll || rr < l) return;
    if(ll <= l && r <= rr) {
      ada[p] = 1;
      for(int i = 0; i < 4; i++) {
        push[i][p] += will[i];
        push[i][p] %= mod;
      }
      relax(p, l, r);
      return;
    }
    int mid = (l + r) >> 1;
    add(p + p, l, mid, ll, rr);
    add(p + p + 1, mid + 1, r, ll, rr);
    combine(p);
  }
  long long get(int l, int r) {
    return get(1, 0, MAX - 1, l, r);
  }
  long long get(int p, int l, int r, int ll, int rr) {
    relax(p, l, r);
    if(r < ll || rr < l) return 0;
    if(ll <= l && r <= rr) return ans[p];
    int mid = (l + r) >> 1;
    long long lef = get(p + p, l, mid, ll, rr);
    long long rig = get(p + p + 1, mid + 1, r, ll, rr);
    combine(p);
    return (lef + rig) % mod;
  }
  vector<long long> sum[4], push[4], ans;
  vector<bool> ada;
};

int main() {
  int t;
  scanf("%d", &t);
  segtree seg;
  for(int tt = 1; tt <= t; tt++) {
    printf("Case #%d:\n", tt);
    int n;
    scanf("%d", &n);
    seg.refresh();
    while(n--) {
      char c;
      int l, r;
      scanf(" %c %d %d", &c, &l, &r);
      for(int i = 3; i >= 0; i--) {
        scanf("%lld", will + i);
        will[i] %= mod;
        if(will[i] < 0) will[i] += mod;
      }
      if(c == 'p') {
        seg.add(l, r);
      } else {
        long long E = seg.get(l, r);
        int r1 = (E * l) % MAX;
        int r2 = (E * r) % MAX;
        l = min(r1, r2);
        r = max(r1, r2);
        seg.add(l, r);
        printf("%lld\n", E);
      }
    }
  }
  
  return 0;
}
