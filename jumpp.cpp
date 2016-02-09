#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

int h[N], n;

struct segtree {
  segtree() {}
  segtree(int n) : n(n) {
    num.resize((n + 2) << 2);
  }
  void update(int at, int val) {
    update(1, 0, n + 1, at, val);
  }
  void find(int l, int r) {
    return find(1, 0, n + 1, l, r);
  }
  void update(int p, int l, int r, int at, int val) {
    if(l == r) {
      num[p] = val;
      return;
    }
    int mid = (l + r) >> 1;
    update(p + p, l, mid, at, val);
    update(p + p + 1, mid + 1, r, at, val);
    num[p] = max(num[p + p], num[p + p + 1]);
  }
  int find(int p, int l, int r, int ll, int rr) {
    if(ll <= l && r <= rr) return num[p];
    if(r < ll || rr < l) return 0;
    int mid = (l + r) >> 1;
    return max(find(1, 0, n + 1, ll, rr), find(1, 0, n + 1, ll, rr));
  }
  int n;
  vector<int> num;
};

segtree seg[N][2];

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", h + i);
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < 2; j++) {
      seg[i][j] = seg(n);
    }
  }
  for(int len = 0; len <= n; len++) {
    
  }
  return 0;
}
