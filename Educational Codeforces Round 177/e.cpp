#include <bits/stdc++.h>

using namespace std;

map<pair<long long, long long>, long long> dp;
vector<long long> z;

long long solve(long long r, long long k) {
  if (r < 0) return 0;
  if (k < 0) return 0;
  if (r == 0) return k == 0;
  if (dp.count({r, k})) return dp[{r, k}];
  int p = upper_bound(z.begin(), z.end(), r) - z.begin() - 1;
  long long up = z[p];
  long long ans = solve(up - 1, k) + solve(r - up, k - 1);
  return dp[{r, k}] = ans;
}

int main() {
  long long now = 0;
  for (int i = 0; i < 63; i += 2) {
    now += (1LL << i);
    z.push_back(now);
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    long long l, r, k;
    scanf("%lld %lld %lld", &l, &r, &k);
    printf("%lld\n", solve(r, k) - solve(l - 1, k));
  }

  return 0;
}
