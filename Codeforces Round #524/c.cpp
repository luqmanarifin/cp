#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <utility>
#include <functional>
#include <cassert>

using namespace std;

long long n, m;

#define point pair<long long, long long>

// segmen
point overlap(point a, point b) {
  if (a.first > b.first) swap(a, b);
  int l = b.first;
  int r = min(a.second, b.second);
  if (l <= r) return make_pair(l, r);
  return {-1, -1};
}

// titik
long long white(point a, point b) {
  if (a.first == -1 || a.second == -1 || b.first == -1 || b.second == -1) return 0;
  long long dx = b.first - a.first + 1;
  long long dy = b.second - a.second + 1;
  long long panjangy = (dy + 1) / 2;
  long long pendeky = dy / 2;
  long long panjangx = (dx + 1) / 2;
  long long pendekx = dx / 2;
  if (a.first % 2 == a.second % 2) {
    return panjangx * panjangy + pendekx * pendeky;
  } else {
    return pendekx * panjangy + pendeky * panjangx;
  }
}

long long black(point a, point b) {
  if (a.first == -1 || a.second == -1 || b.first == -1 || b.second == -1) return 0;
  return (b.first - a.first + 1) * (b.second - a.second + 1) - white(a, b);
}

long long tot(point a, point b) {
  if (a.first == -1 || a.second == -1 || b.first == -1 || b.second == -1) return 0;
  return (b.first - a.first + 1) * (b.second - a.second + 1);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%lld %lld", &n, &m);
    point ap, aq, bp, bq;
    scanf("%lld %lld %lld %lld", &ap.first, &ap.second, &aq.first, &aq.second);
    scanf("%lld %lld %lld %lld", &bp.first, &bp.second, &bq.first, &bq.second);
    point sp = make_pair(1, 1);
    point sq = make_pair(n, m);
    point cx = overlap(point(ap.first, aq.first), point(bp.first, bq.first));
    point cy = overlap(point(ap.second, aq.second), point(bp.second, bq.second));
    point cp = point(cx.first, cy.first);
    point cq = point(cx.second, cy.second);
    long long putih = white(sp, sq) - white(ap, aq) - white(bp, bq) + white(cp, cq) + tot(ap, aq) - tot(cp, cq);
    long long hitam = black(sp, sq) - black(ap, aq) - black(bp, bq) + black(cp, cq) + tot(bp, bq);
    printf("%lld %lld\n", putih, hitam);
  }

  return 0;
}
