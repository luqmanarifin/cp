#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const int inf = 1e9;

vector<int> edge[N];

int cnt[N], mk[N];
int lef[N], rig[N], pt;
// cnt - maksimum - indeks
tuple<int, int, int> a[N];

void dfs(int now) {
  lef[now] = pt++;
  cnt[now] = 1;
  mk[now] = 0;
  for(auto it : edge[now]) {
    dfs(it);
    cnt[now] += cnt[it];
    mk[now] = max(mk[now], cnt[it]);
  }
  a[lef[now]] = make_tuple(cnt[now], -mk[now], now);
  rig[now] = pt - 1;
}

struct segtree {
  segtree(int n) : n(n) {
    num.resize(n << 2);
    build(1, 0, n - 1);
  }

  void build(int p, int l, int r) {
    num[p].resize(r - l + 1);
    if(l == r) {
      num[p][0] = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    merge(num[p + p].begin(), num[p + p].end(), num[p + p + 1].begin(), num[p + p + 1].end(), num[p].begin());
    /*
    printf("%d %d\n", get<2>(a[l]), get<2>(a[r]));
    for(auto it : num[p]) {
      int s, t, u;
      tie(s, t, u) = it;
      printf("%d %d %d\n", s, t, u);
    }
    */
    for(int i = (int) num[p].size() - 2; i >= 0; i--) {
      int al, ar, bl, br, cr, cl;
      tie(cr, ar, br) = num[p][i + 1];
      tie(cl, al, bl) = num[p][i];
      if(al < ar) {
        num[p][i] = make_tuple(cl, ar, br);
      }
    }
  }

  int find(int l, int r, int ma, int mb) {
    return find(1, 0, n - 1, l, r, ma, mb);
  } 

  int find(int p, int l, int r, int ll, int rr, int ma, int mb) {
    if(ll <= l && r <= rr) {
      int low = lower_bound(num[p].begin(), num[p].end(), make_tuple(ma, -inf, -inf)) - num[p].begin();
      if(low < num[p].size()) {
        int s, t, u;
        tie(s, t, u) = num[p][low];
        if(mb <= t) {
          return u;
        } else {
          return -1;
        }
      } else {
        return -1;
      }
    }
    int mid = (l + r) >> 1, ret = -1;
    if(ll <= mid) {
      ret = max(ret, find(p + p, l, mid, ll, min(mid, rr), ma, mb));
    }
    if(mid < rr) {
      ret = max(ret, find(p + p + 1, mid + 1, r, max(mid + 1, ll), rr, ma, mb));
    }
    return ret;
  }

  int n;
  vector<vector<tuple<int, int, int>>> num;
};

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for(int i = 2; i <= n; i++) {
    int num;
    scanf("%d", &num);
    edge[num].push_back(i);
  }
  dfs(1);
  assert(pt == n);
  segtree seg(n);
  while(q--) {
    int now;
    scanf("%d", &now);
    int ans = seg.find(lef[now], rig[now], cnt[now]/2 + cnt[now]%2, -(cnt[now]/2));
    assert(ans != -1);
    printf("%d\n", ans);
  }
  return 0;
}
