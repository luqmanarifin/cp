#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e8;

vector<int> at;
vector<pair<int, int> > pos;

struct segtree {
  segtree() {
    for (int i = 0; i < 3; i++) {
      a[i].resize(pos.size() << 2);
    }
    push.resize(pos.size() << 2);
    build(1, 0, pos.size() - 1);
  }
  void relax(int p, int l, int r) {
    if (push[p] != -1) {
      if (l < r) {
        push[p+p] = push[p];
        push[p+p+1] = push[p];
      }
      long long n = pos[r].second - pos[l].first + 1;
      a[0][p] = n * push[p] % mod;

      // need to not get overflow on this part
      a[1][p] = (n*(n-1)/2) % mod * push[p]*push[p] % mod;
      a[2][p] = (n*(n-1)/2%mod*(n-2)%mod*(66666667)%mod) % mod * push[p]*push[p]%mod*push[p] % mod;
      push[p] = -1;
    }
  }
  void combine(int p, int l, int r) {
    a[0][p] = (a[0][p+p] + a[0][p+p+1]) % mod;
    a[1][p] = (a[1][p+p] + a[1][p+p+1] + a[0][p+p] * a[0][p+p+1]) % mod;
    a[2][p] = (a[2][p+p] + a[2][p+p+1] + a[0][p+p] * a[1][p+p+1] + a[1][p+p] * a[0][p+p+1]) % mod;
  }
  tuple<long long, long long, long long> combine(tuple<long long, long long, long long> lef, tuple<long long, long long, long long> rig) {
    long long a0_lef, a1_lef, a2_lef, a0_rig, a1_rig, a2_rig;
    tie(a0_lef, a1_lef, a2_lef) = lef;
    tie(a0_rig, a1_rig, a2_rig) = rig;
    long long a0 = 0, a1 = 0, a2 = 0;
    a0 = (a0_lef + a0_rig) % mod;
    a1 = (a1_lef + a1_rig + a0_lef * a0_rig) % mod;
    a2 = (a2_lef + a2_rig + a0_lef * a1_rig + a1_lef * a0_rig) % mod;
    return make_tuple(a0, a1, a2);
  }
  void build(int p, int l, int r) {
    push[p] = -1;
    if (l == r) {
      int n = pos[l].second - pos[l].first + 1;
      a[0][p] = n;
      a[1][p] = (1LL*n*(n-1)/2) % mod;
      a[2][p] = (1LL*n*(n-1)*(n-2)/6) % mod;
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    combine(p, l, r);
    //printf("%d: %d %d: ", p, l, r);
    //for (int i = 0; i < 3; i++) printf("%lld ", a[i][p]); printf("\n");
  }
  void update(int l, int r, long long v) {
    update(1, 0, pos.size() - 1, l, r, v);
  }
  void update(int p, int l, int r, int ll, int rr, long long v) {
    relax(p, l, r);
    if (ll <= l && r <= rr) {
      push[p] = v;
      relax(p, l, r);
      return;
    }
    if (r < ll || rr < l) return;
    int mid = (l + r) >> 1;
    update(p + p, l, mid, ll, rr, v);
    update(p + p + 1, mid + 1, r, ll, rr, v);
    combine(p, l, r);
    //printf("%d %d %d: %lld %lld %lld\n", p, l, r, a[0][p], a[1][p], a[2][p]);
  }
  long long find(int l, int r) {
    tuple<long long, long long, long long> ret = find(1, 0, pos.size() - 1, l, r);
    long long ans;
    tie(ignore, ignore, ans) = ret;
    return ans;
  }
  tuple<long long, long long, long long> find(int p, int l, int r, int ll, int rr) {
    relax(p, l, r);
    if (ll <= l && r <= rr) return make_tuple(a[0][p], a[1][p], a[2][p]);
    if (r < ll || rr < l) return make_tuple(0LL, 0LL, 0LL);
    int mid = (l + r) >> 1;
    tuple<long long, long long, long long> lef = find(p + p, l, mid, ll, rr);
    tuple<long long, long long, long long> rig = find(p + p + 1, mid + 1, r, ll, rr);
    combine(p, l, r);
    //printf("FUCK ON DEMAND %d %d %d: %lld %lld %lld\n", p, l, r, a[0][p], a[1][p], a[2][p]);
    tuple<long long, long long, long long> ret = combine(lef, rig);
    return ret;
  }
  vector<long long> a[3], push;
};

int id(int v) {
  return lower_bound(pos.begin(), pos.end(), make_pair(v, v)) - pos.begin();
}

const int N = 1e5 + 5;

char s[N][10];
int l[N], r[N], v[N];

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < q; i++) {
    scanf("%s %d %d", s[i], l + i, r + i);
    if (s[i][0] == 'S') {
      scanf("%d", v + i);
    }
    at.push_back(l[i]);
    at.push_back(r[i]);
  }
  sort(at.begin(), at.end());
  at.resize(distance(at.begin(), unique(at.begin(), at.end())));
  pos.push_back(make_pair(at[0], at[0]));
  int last = at[0];
  for (int i = 1; i < at.size(); i++) {
    if (last + 1 < at[i]) {
      pos.push_back(make_pair(last + 1, at[i] - 1));
    }
    pos.push_back(make_pair(at[i], at[i]));
    last = at[i];
  }
  //for (auto it : pos) printf("%d %d\n", it.first, it.second);
  segtree seg;
  for (int i = 0; i < q; i++) {
    if (s[i][0] == 'S') {
      seg.update(id(l[i]), id(r[i]), v[i]);
    } else {
      printf("%lld\n", seg.find(id(l[i]), id(r[i])));
    }
  }
  return 0;
}
