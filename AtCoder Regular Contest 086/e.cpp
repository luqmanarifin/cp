#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
const long long mod = 1e9 + 7;

vector<int> edge[N], el[N];
long long dp[N][2];
bool matter[N];
int p[N];

void dfs(int now, int h) {
  el[h].push_back(now);
  for (auto it : edge[now]) dfs(it, h + 1);
}

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = power(a, b / 2);
  tmp = tmp * tmp % mod;
  if (b & 1) {
    tmp = tmp * a % mod;
  }
  return tmp;
}

long long inv(long long a) {
  return power(a, mod - 2);
}

void solve(int now) {
  bool ada = 0;
  for (auto it : edge[now]) {
    if (!matter[it]) continue;
    solve(it);
    ada = 1;
  }
  if (!ada) return;
  long long all = 1, allZero = 1;
  for (auto it : edge[now]) {
    if (!matter[it]) continue;
    all = all * (dp[it][0] + dp[it][1]) % mod;
    allZero = allZero * dp[it][0] % mod;
  }
  long long one = 0;
  for (auto it : edge[now]) {
    if (!matter[it]) continue;
    long long add = allZero * dp[it][1] % mod;
    add *= inv(dp[it][0]);
    one += add;
    one %= mod;
  }
  //if (now == 1) printf("%lld %lld %lld\n", all, allZero, one);
  dp[now][1] = one;
  dp[now][0] = (all - one + mod) % mod;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", p + i);
    edge[p[i]].push_back(i);
  }
  dfs(0, 0);
  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    memset(dp, 0, sizeof(dp));
    memset(matter, 0, sizeof(matter));
    for (auto it : el[i]) {
      dp[it][0] = dp[it][1] = 1;
      int now = it;
      while (now) {
        matter[now] = 1;
        now = p[now];
      }
      matter[now] = 1;
    }
    solve(0);
    ans += dp[0][1] * power(2, n + 1 - el[i].size());
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
