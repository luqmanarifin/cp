#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
const int magic = (1 << 30);

struct pos {
  pos(long long _x, long long _y) : x(_x), y(_y) {}
  bool operator==(pos o) {
    return x == o.x && y == o.y;
  }
  long long x, y;
};

long long sum(long long n) {
  return 1LL * n * (n + 1) / 2 % mod;
}

long long sum(long long from, long long to) {
  return sum(to) - sum(from - 1);
}

long long find(pos l, pos r, pos a, pos b, long long offset, int k) {
  //printf("find %I64d %I64d %I64d %I64d\n", l.x, l.y, r.x, r.y);
  int size = r.x - l.x + 1;
  if (l == a && r == b) {
    long long ret = 0;
    if (k <= offset) {
      ret = 0;
    } else if (offset + size <= k) {
      ret = (offset * size % mod * size % mod + sum(size) * size % mod) % mod;
    } else {
      long long to = k - offset;
      long long cnt = to * size % mod;
      ret = (offset * cnt + sum(to) * size) % mod;
    }
    //printf("nah %I64d %I64d %I64d %I64d off %I64d: %I64d\n", l.x, l.y, r.x, r.y, offset, ret);
    return ret;
  }
  long long midx = (l.x + r.x) / 2;
  long long midy = (l.y + r.y) / 2;
  long long ret = 0;
  if (a.x <= midx && a.y <= midy) {
    ret += find(l, pos(midx, midy), a, pos(min(b.x, midx), min(b.y, midy)), offset, k);
  }
  if (a.x <= midx && b.y > midy) {
    ret += find(pos(l.x, midy + 1), pos(midx, r.y), pos(a.x, max(a.y, midy+1)), pos(min(b.x, midx), b.y), offset + size/2, k);
  }
  if (b.x > midx && a.y <= midy) {
    ret += find(pos(midx + 1, l.y), pos(r.x, midy), pos(max(a.x, midx+1), a.y), pos(b.x, min(b.y, midy)), offset + size/2, k);
  }
  if (b.x > midx && b.y > midy) {
    ret += find(pos(midx + 1, midy + 1), r, pos(max(a.x, midx + 1), max(a.y, midy + 1)), b, offset, k);
  }
  return ret % mod;
}

int main() {
  long long q;
  scanf("%I64d", &q);
  while (q--) {
    long long a, b, c, d, k;
    scanf("%I64d %I64d %I64d %I64d %I64d", &a, &b, &c, &d, &k);
    printf("%I64d\n", find(pos(1, 1), pos(magic, magic), pos(a, b), pos(c, d), 0, k));
  }
  return 0;
}