#include <bits/stdc++.h>

using namespace std;

const int N = 3005;
int mod;

long long fact[N], ifact[N], per[N];
long long ways[N], dp[N];

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

long long c(int n, int k) {
  if (n < k || n < 0 || k < 0) return 0;
  long long tmp = fact[n] * ifact[k] % mod;
  tmp = tmp * ifact[n - k] % mod;
  return tmp;
}

int main() {
  int n;
  scanf("%d %d", &n, &mod);
  
  fact[0] = ifact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % mod;
    ifact[i] = inv(fact[i]);
    per[i] = inv(i);
  }
  ways[1] = 1;
  for (int node = 2; node <= n; node++) {
    int til = (node - 1) / 2;
    for (int i = 0; i <= node; i++) dp[i] = 0;
    dp[0] = 1;
    for (int take = 1; take <= til; take++) {
      for (int i = node - 1; i >= 0; i--) {
        long long now = dp[i];
        int sisa = node - 1 - i;
        for (int k = 1; i + k * take < node; k++) {
          now = now * c(sisa, take) % mod * ways[take] % mod * per[k] % mod * take % mod;
          dp[i + k * take] += now;
          dp[i + k * take] %= mod;
          sisa -= take;
        }
      }
      //if (node == 7) printf("%d %lld\n", take, dp[node - 1]);
    }
    ways[node] = dp[node - 1] * node % mod;
  }
  cout << ways[n] << endl;
  return 0;
}
