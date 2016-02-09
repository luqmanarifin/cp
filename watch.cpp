#include <bits/stdc++.h>

using namespace std;

const long long p1 = 13;
const long long p2 = 71;
const long long m1 = 1e9 + 9;
const long long m2 = 2e9 + 89;
const int N = 1e5 + 5;

char s[N];
long long pw1[N], pw2[N];
long long sum1[N], sum2[N];

struct segtree {
public:
  segtree(int _n) : n(_n) {
    num1.resize(n << 2);
    num2.resize(n << 2);
    push.assign(n << 2, -1);
    build(1, 1, n);
  }
  void update(int l, int r, int d) {
    update(1, 1, n, l, r, d);
  }
  pair<long long, long long> get(int l, int r) {
    if(l > r) return make_pair(0, 0);
    return get(1, 1, n, l, r);
  }
private:
  void relax(int p, int l, int r) {
    if(push[p] != -1) {
      num1[p] = (sum1[r] - sum1[l - 1]) * push[p] % m1;
      num2[p] = (sum2[r] - sum2[l - 1]) * push[p] % m2;
      if(num1[p] < 0) num1[p] += m1;
      if(num2[p] < 0) num2[p] += m2;
      if(l < r) {
        push[p + p] = push[p];
        push[p + p + 1] = push[p];
      }
      push[p] = -1;
    }
  }
  void combine(int p, int l, int r) {
    num1[p] = (num1[p + p] + num1[p + p + 1]) % m1;
    num2[p] = (num2[p + p] + num2[p + p + 1]) % m2;
  }
  void build(int p, int l, int r) {
    if(l == r) {
      num1[p] = pw1[l] * (s[l] - '0') % m1;
      num2[p] = pw2[l] * (s[l] - '0') % m2;
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    combine(p, l, r);
  }
  pair<long long, long long> get(int p, int l, int r, int ll, int rr) {
    relax(p, l, r);
    if(r < ll || rr < l) {
      return make_pair(0, 0);
    }
    if(ll <= l && r <= rr) {
      return make_pair(num1[p], num2[p]);
    }
    int mid = (l + r) >> 1;
    pair<long long, long long> lef = get(p + p, l, mid, ll, rr);
    pair<long long, long long> rig = get(p + p + 1, mid + 1, r, ll, rr);
    combine(p, l, r);
    return make_pair((lef.first + rig.first) % m1, (lef.second + rig.second) % m2);
  }
  void update(int p, int l, int r, int ll, int rr, int d) {
    relax(p, l, r);
    if(r < ll || rr < l) return;
    if(ll <= l && r <= rr) {
      push[p] = d;
      relax(p, l, r);
      return;
    }
    int mid = (l + r) >> 1;
    update(p + p, l, mid, ll, rr, d);
    update(p + p + 1, mid + 1, r, ll, rr, d);
    combine(p, l, r);
  }
  vector<long long> num1, num2;
  vector<int> push;
  int n;
};

int main() {
  pw1[0] = pw2[0] = sum1[0] = sum2[0] = 1;
  for(int i = 1; i < N; i++) {
    pw1[i] = pw1[i - 1] * p1 % m1;
    pw2[i] = pw2[i - 1] * p2 % m2;
    sum1[i] = (sum1[i - 1] + pw1[i]) % m1;
    sum2[i] = (sum2[i - 1] + pw2[i]) % m2;
  }
  int n, m, k;
  scanf("%d %d %d %s", &n, &m, &k, s + 1);
  k += m;
  
  segtree seg(n);
  while(k--) {
    int t, l, r, d;
    scanf("%d %d %d %d", &t, &l, &r, &d);
    if(t == 1) {
      seg.update(l, r, d);
    } else {
      pair<long long, long long> lef = seg.get(l, r - d);
      pair<long long, long long> rig = seg.get(l + d, r);
      lef.first = lef.first * pw1[d] % m1;
      lef.second = lef.second * pw2[d] % m2;
      puts(lef == rig? "YES" : "NO");
    }
  }
  return 0;
}
