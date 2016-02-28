#include <bits/stdc++.h>

using namespace std;

#define int long long

struct segtree {
  segtree(int _n, int _k) : n(_n), k(_k) {
    num.resize(k << 2);
    build(1, n - k + 1, n);
  }
  pair<int, int> get() {
    return num[1];
  }
  void update(int at, int val) {
    update(1, n - k + 1, n, at, val);
  }
  void update(int p, int l, int r, int at, int val) {
    if(l == r) {
      num[p] = {val, l};
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
  void build(int p, int l, int r) {
    if(l == r) {
      num[p] = {l * n, l};
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    num[p] = max(num[p + p], num[p + p + 1]);
  }
  
  int n, k;
  vector<pair<int, int>> num;
};

main() {
  int n, k;
  cin >> n >> k;
  segtree seg(n, k);
  for(int i = 0; i < k - 1; i++) {
    pair<int, int> del = seg.get();
    int at = del.second;
    int val = del.first - at;
    seg.update(at, val);
  }
  cout << seg.get().first << endl;
  return 0;
}
