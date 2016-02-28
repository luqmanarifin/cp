#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

vector<int> a, num;

void build(int p, int l, int r) {
  if(l == r) {
    num[p] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(p + p, l, mid);
  build(p + p + 1, mid + 1, r);
  num[p] = min(num[p + p], num[p + p + 1]);
}

int get(int p, int l, int r, int ll, int rr) {
  if(r < ll || rr < l) return inf;
  if(ll <= l && r <= rr) return num[p];
  int mid = (l + r) >> 1;
  return min(get(p + p, l, mid, ll, rr), get(p + p + 1, mid + 1, r, ll, rr));
}

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
  num[p] = min(num[p + p], num[p + p + 1]);
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  a.resize(n);
  num.resize(n << 2);
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  build(1, 0, n - 1);
  while(q--) {
    int i, val, l, r;
    scanf("%d %d %d %d", &i, &val, &l, &r);
    update(1, 0, n - 1, i, val);
    printf("%d\n", get(1, 0, n - 1, l, r));
  }
  
  return 0;
}
