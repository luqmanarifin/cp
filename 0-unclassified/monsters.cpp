#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

// cnt counting how many index have the 'lowest' value in segment tree
int mn[N << 2], cnt[N << 2], push[N << 2];

void build(int p, int l, int r) {
  mn[p] = l;
  cnt[p] = 1;
  push[p] = 0;
  if(l == r) return;
  int mid = (l + r) >> 1;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
}

// propagating lazy segment tree
void gather(int p) {
  int lef = mn[p << 1] + push[p << 1];
  int rig = mn[p << 1 | 1] + push[p << 1 | 1];
  mn[p] = min(lef, rig);
  cnt[p] = (lef == mn[p]? cnt[p << 1] : 0) + (rig == mn[p]? cnt[p << 1 | 1] : 0);
}

void add(int p, int l, int r, int ll, int rr, int val) {
  if(ll <= l && r <= rr) {
    push[p] += val;
    return;
  }
  int mid = (l + r) >> 1;
  if(ll <= mid) {
    add(p << 1, l, mid, ll, rr, val);
  }
  if(mid < rr) {
    add(p << 1 | 1, mid + 1, r, ll, rr, val);
  }
  gather(p);
}

int a[N];

// maintaining stack of increasing value
// this is also the most biggest element on presum from right
// ex    : 60  100  1  2  3
// stack :     100        3
// means : 100 100  3  3  3
int up[N];

// maintaining stack of decreasing value
// this is also the most smallest element on presum from right
int down[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--; y--;
    a[x] = y;
  }
  build(1, 0, n - 1);
  
  int tup = 1;
  int tdown = 1;
  up[0] = -1;
  down[0] = -1;
  long long ans = 0;
  
  for(int i = 0; i < n; i++) {
    // update the stack of increasing value
    while(tup >= 2 && a[i] < a[up[tup - 1]]) {
      // maintaining the 'abs' value of index
      add(1, 0, n - 1, up[tup - 2] + 1, up[tup - 1], a[up[tup - 1]]);
      tup--;
    }
    // update the stack of decreasing value
    while(tdown >= 2 && a[i] > a[down[tdown - 1]]) {
      // maintaining the 'abs' value of index
      add(1, 0, n - 1, down[tdown - 2] + 1, down[tdown - 1], -a[down[tdown - 1]]);
      tdown--;
    }
    up[tup++] = i;
    down[tdown++] = i;
    assert(tup >= 2);
    assert(tdown >= 2);
    // maintaining the 'abs' value of index 
    add(1, 0, n - 1, up[tup - 2] + 1, up[tup - 1], -a[up[tup - 1]]);
    // maintaining the 'abs' value of index
    add(1, 0, n - 1, down[tdown - 2] + 1, down[tdown - 1], a[down[tdown - 1]]);
    ans += cnt[1];
  }
  cout << ans << endl;
  return 0;
}
