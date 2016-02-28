#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int mod = 1e9 + 7;

long long fact[N], ifact[N];
pair<int, int> p[N];
long long dp[N];

long long c(int n, int k) {
  long long temp = fact[n] * ifact[k] % mod;
  temp *= ifact[n - k];
  return temp % mod;
}

long long find(int x, int y) {
  return c(x + y - 2, x - 1);
}

long long power(int a, int b) {
  if(b == 0) return 1;
  long long temp = power(a, b / 2);
  temp *= temp;
  temp %= mod;
  if(b & 1) {
    temp *= a;
    temp %= mod;
  }
  return temp;
}

long long inv(long long a) {
  return power(a, mod - 2);
}

int main() {
  fact[0] = ifact[0] = 1;
  for(int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % mod;
    ifact[i] = inv(fact[i]);
  }
  
  int h, w, n;
  scanf("%d %d %d", &h, &w, &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &p[i].first, &p[i].second);
  }
  sort(p, p + n);
  p[n] = {h, w};
  for(int i = 0; i <= n; i++) {
    dp[i] = find(p[i].first, p[i].second);
    for(int j = 0; j < i; j++) {
      if(p[j].first <= p[i].first && p[j].second <= p[i].second) {
        dp[i] -= dp[j] * find(p[i].first - p[j].first + 1, p[i].second - p[j].second + 1);
        dp[i] %= mod;
        if(dp[i] < 0) {
          dp[i] += mod;
        }
      }
    }
  }
  cout << dp[n] << endl;
  /*
  for(int i = 1; i <= 4; i++) {
    for(int j = 1; j <= 4; j++) {
      cout << find(i, j) << ' ';
    }
    cout << endl;
  }
  */
  return 0;
}
