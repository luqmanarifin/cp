#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const long long mod = 1e9 + 7;

double dp[N][N];
int k, pa, pb;
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

double dfs(int gain, int A) {
  if (vis[gain][A]) return dp[gain][A];
  if (A == 0) return dfs(gain, A + 1);
  if (A == k) return A + (double) pa / pb;
  if (gain >= k) return 0;
  vis[gain][A] = 1;
  double ret = (pa * dfs(gain, A + 1) + pb * (dfs(gain + A, A) + A)) / (pa + pb);
  return dp[gain][A] = ret;
}

int main() {
  scanf("%d %d %d", &k, &pa, &pb);
  printf("%.15f\n", dfs(0, 0));
  for (int i = 1; i <= 10; i++) {
    
  }
  return 0;
}
