
#include <bits/stdc++.h>

using namespace std;

map<tuple<int, long long, long long>, long long> dp;
char s[105];

long long find(int len, long long from, long long to) {
  auto it = make_tuple(len, from, to);
  if (dp.count(it)) return dp[it];
  long long ret = 0;
  for (int i = len - 1; i >= 0; i--) {
    if ((from & (1LL << i)) != (to & (1LL << i))) {
      ret++;
      if (i) {
        long long be = (1LL << (i - 1));
        long long all = (1LL << i) - 1;
        ret += find(i, from & ((1LL << i) - 1), be);
        from &= ~all;
        from |= be;
      }
    }
  }
  return dp[it] = ret;
}

int main() {
  scanf("%s", s);
  int n = strlen(s);
  long long mask = 0;
  for (int i = 0; i < n; i++) {
    mask = mask * 2 + s[i] - '0';
  }
  long long ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (mask & (1LL << i)) {
      ans++;
      if (i) {
        long long be = (1LL << (i - 1));
        long long all = (1LL << i) - 1;
        ans += find(i, mask & all, be);
        //printf("%lld %lld\n", mask & all, be);
        //printf("lol %lld\n", find(i, mask & all, be));
        mask &= ~all;
        mask |= be;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
