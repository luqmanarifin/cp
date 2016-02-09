#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

long long a[N], len, n;

bool valid(long long t) {
  vector< pair<long long, long long> > seg;
  for(long long i = 0; i < n; i++) {
    seg.push_back(make_pair(a[i] - t, a[i] + t / 2));
  }
  pair<long long, long long> now, bef = make_pair(0, 0);
  int it = 0;
  bool ret = 1;
  while(it < seg.size()) {
    now = seg[it];
    if(bef.second + 1 < now.first) {
      ret = 0;
      break;
    }
    bef = now;
    it++;
  }
  if(bef.second < len) {
    ret = 0;
  }
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%lld %lld", &len, &n);
    for(int i = 0; i < n; i++) {
      scanf("%lld", a + i);
    }
    long long l = 0, r = 2 * len;
    while(l < r) {
      long long mid = (l + r) >> 1;
      if(valid(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    printf("%d\n", (int) l);
  }
  return 0;
}
