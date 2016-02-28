#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9;

class segtree {
public:
  segtree(int _n, int _type) : n(_n), type(_type) {
    num.resize(n << 3);
    push.resize(n << 3);
    build(1, 0, 2 * n - 1);
  }
  int get(int at) {
    return _get(1, 0, 2 * n - 1, at);
  }
  void update(int l, int r, int val) {
    if(l <= r) _update(1, 0, 2 * n - 1, l, r, val);
  }
private:
  void build(int p, int l, int r) {
    num[p] = push[p] = inf;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
  }
  void relax(int p, int l, int r) {
    if(push[p] != inf) {
      assert(push[p] >= 0);
      num[p] = min(num[p], push[p]);
      if(l < r) {
        int mid = (l + r) >> 1;
        push[p + p] = min(push[p + p], push[p]);
        push[p + p + 1] = min(push[p + p + 1], push[p] + type*(mid-l+1));
      }
      push[p] = inf;
    }
  }
  int _get(int p, int l, int r, int at) {
    relax(p, l, r);
    if(l == r) return num[p];
    int mid = (l + r) >> 1;
    if(at <= mid) {
      return _get(p + p, l, mid, at);
    } else {
      return _get(p + p + 1, mid + 1, r, at);
    }
  }
  void _update(int p, int l, int r, int ll, int rr, int val) {
    relax(p, l, r);
    if(r < ll || rr < l) return;
    //printf("%d %d %d %d %d\n", l, r, ll, rr, val);
    assert(val >= 0);
    if(ll <= l && r <= rr) {
      push[p] = min(push[p], val);
      relax(p, l, r);
      return;
    }
    int mid = (l + r) >> 1;
    _update(p + p, l, mid, ll, rr, val);
    _update(p + p + 1, mid + 1, r, ll, rr, val + type*max(0,(mid+1-max(ll,l))));
  }
  vector<int> num;
  vector<int> push;
  int n, type;
};

int a[N], b[N], pa[N], pb[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
    a[i]--;
    pa[a[i]] = i;
  }
  for(int i = 0; i < n; i++) {
    scanf("%d", b + i);
    b[i]--;
    pb[b[i]] = i;
  }
  segtree asc(n, 1);
  segtree des(n, -1);
  for(int i = 0; i < n; i++) {
    int c = (pb[i] + n - pa[i]) % n;
    int len = n - pa[i];
    asc.update(c + 1, c + pa[i], 1);
    des.update(c + n - len + 1, c + n, len - 1);
  }
  for(int i = 0; i < n; i++) {
    printf("%d\n", min(min(asc.get(i), asc.get(i + n)), min(des.get(i), des.get(i + n))));
  }
  return 0;
}
