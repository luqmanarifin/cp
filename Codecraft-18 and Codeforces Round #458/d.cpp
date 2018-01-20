#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int a[N], n, num[N << 2];

void build(int p, int l, int r) {
  if (l == r) {
    num[p] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(p + p, l, mid);
  build(p + p + 1, mid + 1, r);
  num[p] = __gcd(num[p + p], num[p + p + 1]);
}

void update(int p, int l, int r, int at, int val) {
  if (l == r) {
    num[p] = val;
    return;
  }
  int mid = (l + r) >> 1;
  if (at <= mid) {
    update(p + p, l, mid, at, val);
  } else {
    update(p + p + 1, mid + 1, r, at, val);
  }
  num[p] = __gcd(num[p + p], num[p + p + 1]);
}

void update(int at, int val) {
  update(1, 1, n, at, val);
}

int ll, rr;
int pp[N], aa[N], bb[N], pt;

int cari(int p, int l, int r, bool st) {
  if (ll <= l && r <= rr) {
    if (st) {
      pp[pt] = p;
      aa[pt] = l;
      bb[pt] = r;
      pt++;
    }
    return num[p];
  }
  if (r < ll || rr < l) return 0;
  int mid = (l + r) >> 1;
  return __gcd(cari(p + p, l, mid, st), cari(p + p + 1, mid + 1, r, st));
}

int cari(int l, int r, bool st = 0) {
  ll = l;
  rr = r;
  if (l > r) return 0;
  return cari(1, 1, n, st);
}

int solve(int p, int l, int r, int bef, int x) {
  if (l == r) return l;
  int mid = (l + r) >> 1;
  int lef = __gcd(bef, num[p + p]);
  if (lef % x) {
    return solve(p + p, l, mid, bef, x);
  } else {
    return solve(p + p + 1, mid + 1, r, lef, x);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  build(1, 1, n);
  int q;
  scanf("%d", &q);
  while (q--) {
    int t, l, r, x, at, val;
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d %d %d", &l, &r, &x);
      pt = 0;
      if (cari(l, r, 1) % x == 0) {
        puts("YES");
        continue;
      }
      int now = 0; at = -1;
      for (int i = 0; i < pt; i++) {
        if (__gcd(now, num[pp[i]]) % x == 0) {
          now = __gcd(now, num[pp[i]]);
        } else {
          at = solve(pp[i], aa[i], bb[i], now, x);
          break;
        }
      }
      //printf("at %d\n", at);
      assert(at != -1);
      int ret = __gcd(cari(l, at - 1), cari(at + 1, r));
      puts(ret % x == 0? "YES" : "NO");
    } else {
      scanf("%d %d", &at, &val);
      update(at, val);
    }
  }
  
  return 0;
}
