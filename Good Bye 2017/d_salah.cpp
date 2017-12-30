#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const long long mod = 1e9 + 7;

long long dp[N][N];
int k, pa, pb;
long long inv_pb, inv_pa_pb;
bool vis[N][N];

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long temp = power(a, b / 2);
  temp = temp * temp % mod;
  if (b & 1) temp = temp * a % mod;
  return temp;
}

long long inv(long long a) {
  return power(a, mod - 2);
}

long long dfs(int gain, int A) {
  if (gain >= k) return 0;
  if (vis[gain][A]) return dp[gain][A];
  if (A == 0) return dfs(gain, A + 1);
  if (A == k) return (A + pa * inv_pb) % mod;
  vis[gain][A] = 1;
  long long ret = (pa*dfs(gain, A + 1)%mod + pb*(dfs(gain + A, A) + A)%mod) * inv_pa_pb % mod;
  return dp[gain][A] = ret;
}

int main() {
  scanf("%d %d %d", &k, &pa, &pb);
  inv_pb = inv(pb);
  inv_pa_pb = inv((pa + pb) % mod);
  printf("%lld\n", dfs(0, 0));
  return 0;
}