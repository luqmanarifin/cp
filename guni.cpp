#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

struct segtree {
public:
  segtree(int n) : n(n) {
    num.resize(n << 2);
  }
  void update(int at, int val) {
    update(1, 0, n - 1, at, val);
  }
  int get(int l, int r) {
    return get(1, 0, n - 1, l, r);
  }
private:
  void update(int p, int l, int r, int at, int val) {
    if(l == r) {
      num[p] = val;
      return;
    }
    int mid = (l + r) >> 1;
    if(at <= mid) {
      update(p + p, l, mid, at, val);
    } else {
      update(p + p + 1, mid + 1, r, at, val);
    }
    num[p] = max(num[p + p], num[p + p + 1]);
  }
  int get(int p, int l, int r, int ll, int rr) {
    if(ll <= l && r <= rr) return num[p];
    if(r < ll || rr < l) return 0;
    int mid = (l + r) >> 1;
    return max(get(p + p, l, mid, ll, rr), get(p + p + 1, mid + 1, r, ll, rr));
  }
  vector<int> num;
  int n;
};

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  segtree a(n), b(m);
  for(int i = 0; i < n; i++) {
    int val;
    scanf("%d", &val);
    a.update(i, val);
  }
  for(int i = 0; i < m; i++) {
    int t, l, r, val;
    scanf("%d %d %d", &t, &l, &r);
    l--; r--;
    val = (t == 1? a : b).get(l, r);
    printf("%d\n", val);
    b.update(i, val);
  }
  return 0;
}
