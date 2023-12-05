#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long inf = 1e18;

int lef[N], rig[N], n;

pair<long long, long long> cut(pair<long long, long long> a, pair<long long, long long> b) {
  if (a > b) swap(a, b);
  if (a.second < b.first) return make_pair(inf, inf);
  return make_pair(b.first, min(a.second, b.second));
}

bool can(int k) {
  pair<long long, long long> now = make_pair(0, 0);
  // printf("K = %d\n", k);
  for (int i = 0; i < n; i++) {
    now = make_pair(now.first - k, now.second + k);
    auto res = cut(now, make_pair(lef[i], rig[i]));
    // printf("cut %d %d & %d %d = %d %d\n", now.first, now.second, lef[i], rig[i], res.first, res.second);
    if (res == make_pair(inf, inf)) return 0;
    now = res;
  }
  return 1;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d %d", lef + i, rig + i);
    }
    int l = 0, r = 1e9;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (can(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    printf("%d\n", l);
  }

  return 0;
}
