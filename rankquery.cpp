#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;
const int inf = 1e9 + 5;

vector<int> num[N << 2];
int a[N];

void build(int p, int l, int r) {
  num[p].resize(r - l + 1);
  if(l == r) {
    num[p][0] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(p + p, l, mid);
  build(p + p + 1, mid + 1, r);
  merge(num[p+p].begin(), num[p+p].end(), num[p+p+1].begin(), num[p+p+1].end(), num[p].begin());
}

int ll, rr, v;

int query(int p, int l, int r) {
  if(ll <= l && r <= rr) {
    return upper_bound(num[p].begin(), num[p].end(), v) - num[p].begin();
  }
  if(r < ll || rr < l) return 0;
  int mid = (l + r) >> 1;
  return query(p + p, l, mid) + query(p + p + 1, mid + 1, r);
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++) {
      scanf("%d", a + i);
    }
    build(1, 1, n);
    printf("Case #%d:\n", tt);
    while(q--) {
      int l, r, k;
      scanf("%d %d %d", &l, &r, &k);
      ll = l; rr = r;
      
      int lef = 0, rig = inf;
      while(lef < rig) {
        int mid = (lef + rig) >> 1;
        v = mid;
        if(query(1, 1, n) < k) {
          lef = mid + 1;
        } else {
          rig = mid;
        }
      }
      printf("%d\n", lef);
    }
    
  }
  
  return 0;
}
