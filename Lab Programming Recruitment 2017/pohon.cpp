#include <bits/stdc++.h>

using namespace std;

const long long N = 3005;

set<long long> depth[N];
long long lef[N], rig[N], h[N], cnt;
long long a[N];

void find(long long at, long long val) {
  if (a[at] < val) {
    if (rig[at] == -1) {
      rig[at] = cnt;
      a[cnt] = val;
      h[cnt] = h[at] + 1;
      depth[h[cnt]].insert(val);
      cnt++;
    } else {
      find(rig[at], val);
    }
  } else {
    if (lef[at] == -1) {
      lef[at] = cnt;
      a[cnt] = val;
      h[cnt] = h[at] + 1;
      depth[h[cnt]].insert(val);
      cnt++;
    } else {
      find(lef[at], val);
    }
  }
}

int main() {
  memset(lef, -1, sizeof(lef));
  memset(rig, -1, sizeof(rig));

  long long n;
  scanf("%lld", &n);
  while (n--) {
    long long t, d, e;
    long long v;
    scanf("%lld", &t);
    if (t == 1) {
      scanf("%lld", &v);
      if (cnt == 0) {
        a[cnt] = v;
        h[cnt] = 1;
        depth[h[cnt]].insert(v);
        cnt++;
      } else {
        find(0, v);
      }
    } else {
      scanf("%lld %lld", &d, &e);
      e = depth[d].size() - e;
      long long p = 0;
      for (long long it : depth[d]) {
        if (p == e) {
          cout << it << endl;
        }
        p++;
      }
    } 
  }

  return 0;
}
