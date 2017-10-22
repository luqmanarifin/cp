#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;
const long long MAX = 2e7;

long long f, T, t0;
long long a1, t1, p1;
long long a2, t2, p2;

long long solve(long long buy1, long long buy2) {
  vector<pair<long long, long long>> k;
  k.emplace_back(t0, f);
  k.emplace_back(t1, buy1 * a1);
  k.emplace_back(t2, buy2 * a2);
  long long total_t = 0;
  long long kuota = f;
  sort(k.begin(), k.end());
  for (auto it : k) {
    long long rem = min(kuota, it.second);
    total_t += rem * it.first;
    kuota -= rem;
  }
  if (total_t <= T) {
    return buy1 * p1 + buy2 * p2;
  } else {
    return inf;
  }
}

long long solve(long long buy1) {
  long long l = 0, r = MAX;
  while (r - l > 3) {
    long long lf = (l + l + r) / 3;
    long long rf = (l + r + r) / 3;
    if (solve(buy1, lf) < solve(buy1, rf)) {
      r = rf;
    } else {
      l = lf;
    }
  }
  long long ans = inf;
  for (long long i = l; i <= r; i++) ans = min(ans, solve(buy1, i));
  return ans;
}

int main() {
  scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld", &f, &T, &t0, &a1, &t1, &p1, &a2, &t2, &p2);
  long long l = 0, r = MAX;
  while (r - l > 3) {
    long long lf = (l + l + r) / 3;
    long long rf = (l + r + r) / 3;
    if (solve(lf) < solve(rf)) {
      r = rf;
    } else {
      l = lf;
    }
  }
  long long ans = inf;
  for (long long i = l; i <= r; i++) ans = min(ans, solve(i));
  if (ans == inf) ans = -1;
  cout << ans << endl;
  return 0;
}
